#ifndef IRAKLI_EXTERN_H
#define IRAKLI_EXTERN_H

#include<vector>
#include<map>
#include<string>

extern std::string runType;
extern int globalJ;
extern bool withTCORR;
extern bool doIt;
extern bool onceDone;
extern bool isData;
extern bool complexT;
extern bool debug;
extern std::string finalFileName;
extern std::vector<double> epsilon;
extern int NPAR;
extern std::map<int, std::vector<double> > myAmplitudes;
extern bool accOnce;

#endif
