#include "TFile.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TDirectory.h"


{
  
TFile *f=new TFile("physval-21.3test.root");

cout<<"1"<<endl;

  TCanvas *c = new TCanvas("c","c",1000,1000);
cout<<"2"<<endl;
  gDirectory->cd("run_1/HLT/TauMon/Expert");
  cout<<"3"<<endl;
  TProfile *h1;
 cout<<"4"<<endl;
  std::vector<TString>Hist=
    {
      "tau25_idperf_tracktwoMVA",
      "tau25_idperf_tracktwoRNN",
      "tau25_idperf_tracktwoMVABDT",
      
    };
cout<<"5"<<endl;
    for (int i=0; i<Hist.size();i++){
            gDirectory->cd(Hist[i]+"/TurnOnCurves/RecoEfficiency");
cout<<"6"<<endl;      
h1=(TProfile*)f->Get("TProfRecoL1PtEfficiency");
   
cout<<"7"<<endl;      
      if (i>0){
      h1->Draw("same");
cout<<"8"<<endl;      
gDirectory->cd("../../../");
cout<<"9"<<endl;
      }
      
          else {

	   h1->Draw();
cout<<"10"<<endl;	 
  gDirectory->cd("../../../");
cout<<"11"<<endl;
          }

      
    } 

}
