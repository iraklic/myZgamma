#include<TMinuit.h>
#include<stdio.h>
#include<math.h>
#include<string.h>

#include<TCanvas.h>
#include<TH1F.h>
//A toy example of how to use MINUIT with user-defined function.
//
//

//static void chi2exp_m(int& numpar,double* grad,double& fval,double* par,int iflag)
//{
//  fval =  chi2exp(par[0]);
//}


void chisq(int& numpar,double* grad,double& fval,double* par,int iflag)
{
 
  char   RED[] = "\033[1;31m";
  char   BLACK[] = "\033[0m";
  char*  color;
  static int first_run=1;
  static double oldpar[100];
  
  int i=0;
  if(first_run){
	  if(numpar>99) {
		  printf("TOO many parameters!!!\n");
		  return;
	  }
	  memcpy(oldpar,par,numpar*sizeof(double));
	  first_run=0;
  }
  
  for(i=0;i<numpar;i++){
	  if(fabs(par[i]-oldpar[i])>0.000001)
		  color=RED;
	  else color=BLACK;
	  printf("%s par[%i] = %f %s\n",color,i,par[i],BLACK);
  }
 
  memcpy(oldpar,par,numpar*sizeof(double));
 
  //calculate your value and assign it to fval
  fval=(par[0]+3)*(par[0]+3)+(par[1]-5)*(par[1]-5);
 
  printf("--------------- chisq returned value %f -----------------\n",fval);
  return;
}

int main(void)
{
  int ierflag;
  TMinuit *gM = new TMinuit(200);

  gM->mncomd("set nogradient",ierflag);
  gM->mncomd("set eps 0.00001",ierflag);
  gM->mncomd("set err 0.5",ierflag);
  
  gM->SetFCN(chisq);
 
  //arguments: parameter number, initial value, initial step, low limit, high limit
  gM->mnparm(0,"x_pos", 0, 0.5, -150, 150.0, ierflag);
  gM->mnparm(1,"y_pos", 0, 0.2, -50.0, 50.0, ierflag);
  
  //fixing parameters
  gM->FixParameter(0);
  gM->FixParameter(1);

  //release some parameters and fit them
  gM->Release(0);
  gM->Release(1);
  gM->mncomd("migrad",ierflag);
  //fix some parameters
  //gM->FixParameter(0);     
  //gM->FixParameter(1);     

  FILE* ou;
  ou = fopen("fitrezult.txt","w");
  TString pname;
  double p1,val,err;
  int i1;
  int i;
 
  for(i=0;i<2;i++){
    gM->mnpout((int)i,pname,val,err,p1,p1,i1);
    fprintf(ou,"%s = %10.6f +- %f \n",pname.Data(),val,err);
  }
  fprintf(ou,"\n");
  fclose(ou);
  
  delete gM;

  TCanvas c1("c1","c1",60,60,600,600);
  c1.cd();
  TH1F h("h","h",10,0,10);
  h.Draw();
  c1.Update();
  sleep(10);
  return 0;
}

