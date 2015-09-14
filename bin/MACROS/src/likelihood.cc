#include "TROOT.h"
#include "TMinuit.h"
#include "TMath.h"

#include <iostream>

#ifdef __SC__
long G__globalvarpointer; // To make the Symantec linker happy
#endif

extern void fcnk0(Int_t &npar, Double_t *gin, Double_t &f, Double_t *x, Int_t iflag);

static int ncount = 0;

VoidFuncPtr_t dictfuncs[] = { NULL };

using namespace std;

//______________________________________________________________________________
int main()
	{
	TROOT minexam("TestMinuit","Test of Minuit", dictfuncs);

	static Int_t nprm[5]		= { 0,	1,	4,	9,	10};
	static Double_t vstrt[5]	= {0.,	0.,	.535,	.892,	518.3};
	static Double_t stp[5]		= {0.1,	0.1,	0.1,	0.,	0.};
	static Double_t p0=0;
	static Double_t p1=1;
	static Double_t p3=3;
	static Double_t p5=5;
	Int_t ierflg = 0;

	TMinuit *gMinuit = new TMinuit(5);  //initialize TMinuit with a maximum of 5 params

	gMinuit->mninit(5,6,7);
	gMinuit->SetFCN(fcnk0);

	gMinuit->mnparm(nprm[0], "Re(X)",    vstrt[0], stp[0], 0,0,ierflg);
	gMinuit->mnparm(nprm[1], "Im(X)",    vstrt[1], stp[1], 0,0,ierflg);
	gMinuit->mnparm(nprm[2], "Delta M",  vstrt[2], stp[2], 0,0,ierflg);
	gMinuit->mnparm(nprm[3], "T Kshort", vstrt[3], stp[3], 0,0,ierflg);
	gMinuit->mnparm(nprm[4], "T Klong",  vstrt[4], stp[4], 0,0,ierflg);
	if (ierflg)
		{
		Printf(" UNABLE TO DEFINE PARAMETER NO.");
		return ierflg;
		}
//	gMinuit->mnseti("Time Distribution of Leptonic K0 Decays");
//*-*-	Request FCN to read in (or generate random) data (IFLAG=1)
//	gMinuit->mnexcm("CALL FCN", &p1 ,1,ierflg);

//	gMinuit->mnexcm("FIX", &p5 ,1,ierflg);
//	gMinuit->mnexcm("SET PRINT", &p0 ,1,ierflg);
//	gMinuit->mnexcm("MIGRAD", &p0 ,0,ierflg);
//	gMinuit->mnexcm("MINOS", &p0 ,0,ierflg);
//	gMinuit->mnexcm("RELEASE", &p5 ,1,ierflg);
//	gMinuit->mnexcm("MIGRAD", &p0 ,0,ierflg);
//	gMinuit->mnexcm("MINOS",  &p0 ,0,ierflg);
//	gMinuit->mnexcm("CALL FCN", &p3 , 1,ierflg);

	return 0;
	}

//______________________________________________________________________________
void fcnk0(Int_t &npar, Double_t *gin, Double_t &f, Double_t *x, Int_t iflag)
	{
	const Int_t MXBIN=50;
	static Double_t thplu[MXBIN],thmin[MXBIN],t[MXBIN];
	static Int_t nbins = 30;
	static Int_t nevtot = 250;
	static Double_t evtp[30] =	{
					11.,  9., 13., 13., 17.,  9.,  1.,  7.,  8.,  9.,
					 6.,  4.,  6.,  3.,  7.,  4.,  7.,  3.,  8.,  4.,
					 6.,  5.,  7.,  2.,  7.,  1.,  4.,  1.,  4.,  5.};
	static Double_t evtm[30] =	{
					0.,  0.,  0.,  0.,  0.,  0.,  0.,  0.,  1.,  1.,
					0.,  2.,  1.,  4.,  4.,  2.,  4.,  2.,  2.,  0.,
					2.,  3.,  7.,  2.,  3.,  6.,  2.,  4.,  1.,  5.};

	static Int_t i, nevplu, nevmin;
	static Double_t xre, xim, dm, gams, gaml,gamls,xr1,xr2,em,ep;
	static Double_t sthplu, sthmin, ehalf, th, sterm, sevtp, sevtm;
	static Double_t thplui, thmini, chisq, ti, thp, thm, evp, evm, chi1, chi2;

	xre   = x[0];
	xim   = x[1];
	dm    = x[4];
	gams  = 1/x[9];
	gaml  = 1/x[10];
	gamls = 0.5*(gaml+gams);
	if (iflag != 1)  goto L300;

//	generate random data
	sthplu = sthmin = 0;
	for (i=1;i<=nbins; i++)
		{
		t[i-1] = 0.1*Double_t(i);
		ti = t[i-1];
		ehalf = TMath::Exp(-ti*gamls);
		xr1 = 1-xre;
		xr2 = 1+xre;
		th =      (xr1*xr1 + xim*xim) * TMath::Exp(-ti*gaml);
		th = th + (xr2*xr2 + xim*xim) * TMath::Exp(-ti*gams);
		th = th -               4*xim*TMath::Sin(dm*ti) * ehalf;
		sterm = 2*(1-xre*xre-xim*xim)*TMath::Cos(dm*ti) * ehalf;
		thplu[i-1] = th + sterm;
		thmin[i-1] = th - sterm;
		sthplu += thplu[i-1];
		sthmin += thmin[i-1];
		}
	nevplu = Int_t(Double_t(nevtot)*(sthplu/(sthplu+sthmin)));
	nevmin = Int_t(Double_t(nevtot)*(sthmin/(sthplu+sthmin)));
	cout<<"  LEPTONIC K ZERO DECAYS"<<endl;
	cout<<Form(" PLUS, MINUS, TOTAL=%5d %5d %5d",nevplu,nevmin,nevtot)<<endl;
	cout<<"0      TIME       THEOR+      EXPTL+      THEOR-      EXPTL-"<<endl;
	sevtp = sevtm = 0;
	for (i=1;i<=nbins; i++)
		{
		thplu[i-1] = thplu[i-1]*Double_t(nevplu) / sthplu;
		thmin[i-1] = thmin[i-1]*Double_t(nevmin) / sthmin;
		thplui = thplu[i-1];
		sevtp += evtp[i-1];
		thmini = thmin[i-1];
		sevtm += evtm[i-1];
		if (iflag != 4)
			{
			cout<<Form("%12.4f%12.4f%12.4f%12.4f%12.4f",t[i-1],thplu[i-1],evtp[i-1],thmin[i-1],evtm[i-1])<<endl;
			}
		}
	cout<<Form(" DATA EVTS PLUS, MINUS= %10.2f%10.2f", sevtp,sevtm)<<endl;

//	calculate chisquared
	L300:
	chisq = sthplu = sthmin = 0;
	for (i=1;i<=nbins; i++)
		{
		ti = t[i-1];
		ehalf = TMath::Exp(-ti*gamls);
		xr1 = 1-xre;
		xr2 = 1+xre;
		th =      (xr1*xr1 + xim*xim) * TMath::Exp(-ti*gaml);
		th = th + (xr2*xr2 + xim*xim) * TMath::Exp(-ti*gams);
		th = th -               4*xim*TMath::Sin(dm*ti) * ehalf;
		sterm = 2*(1-xre*xre-xim*xim)*TMath::Cos(dm*ti) * ehalf;
		thplu[i-1] = th + sterm;
		thmin[i-1] = th - sterm;
		sthplu += thplu[i-1];
		sthmin += thmin[i-1];
		}
	thp = thm = evp = evm = 0;
	if (iflag != 4) cout<<"          POSITIVE LEPTONS                    ,NEGATIVE LEPTONS"<<endl;

	if (iflag != 4)
		{
		cout<<"      TIME    THEOR    EXPTL    chisq         TIME    THEOR    EXPTL    chisq"<<endl;
		}
	for (i=1;i<=nbins; i++)
		{
		thplu[i-1] = thplu[i-1]*sevtp / sthplu;
		thmin[i-1] = thmin[i-1]*sevtm / sthmin;
		thp += thplu[i-1];
		thm += thmin[i-1];
		evp += evtp[i-1];
		evm += evtm[i-1];
//		Sum over bins until at least four events found
		if (evp > 3)
			{
			ep   = evp-thp;
			chi1 = (ep*ep)/evp;
			chisq = chisq + chi1;
			if (iflag != 4)
				{
				cout<<Form(" %9.3f%9.3f%9.3f%9.3f",t[i-1],thp,evp,chi1)<<endl;
				}
			thp = evp = 0;
			}
		if (evm > 3)
			{
			em   = evm-thm;
			chi2 = (em*em)/evm;
			chisq = chisq + chi2;
			if (iflag != 4)
				{
				cout<<Form("                    %9.3f%9.3f%9.3f%9.3f",t[i-1],thm,evm,chi2)<<endl;
				}
			thm = evm = 0;
			}
		}
	f = chisq;
	ncount++;
//	cout<<ncount<< " F= "<<f<<" xre="<<xre<<" xim="<<xim<<" dm="<<dm<<" gams="<<gams<<" gaml="<<gaml<<endl;
	}
