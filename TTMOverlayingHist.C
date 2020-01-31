#include "TFile.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TDirectory.h"


{
  
TFile *f=new TFile("physval-21.3test.root");

  TCanvas *c = new TCanvas("c","TProfile Histogram",1000,1000);
  gDirectory->cd("run_1/HLT/TauMon/Expert");
  TProfile *h;
  std::vector<TString>Hist=
    {
      "tau25_idperf_tracktwoMVA",
      "tau25_idperf_tracktwoRNN",
      "tau25_idperf_tracktwoMVABDT",
     };

    for (int i=0; i<Hist.size();i++){
            gDirectory->cd(Hist[i]+"/TurnOnCurves/RecoEfficiency");
            h=(TProfile*)f->Get("TProfRecoL1PtEfficiency");     
     
      if (i>0){
        h->Draw("same");
        gDirectory->cd("../../../");
      }
      
      else {
	h->Draw();
        gDirectory->cd("../../../");
           }
      } 

}
