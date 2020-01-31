#include "TFile.h"
#include "TProfile.h"
#include "TCanvas.h"
#include "TDirectory.h"
#include <iostream>


void makePlot(){
  
  TFile *f=TFile::Open("physval-21.3test.root","READ");

  cout<<"1. Open a Root File"<<endl;

  TCanvas *c = new TCanvas("c","TProfile Histogram",1500,1500);
  c->Draw();
  cout<<"2. Create the canvas"<<endl;
  TProfile *h;
  cout<<"3. set h pointer as TProfile class"<<endl;
  std::vector<TString>Hist=
    {
      "tau25_idperf_tracktwoMVA",
      "tau25_idperf_tracktwoRNN",
      "tau25_idperf_tracktwoMVABDT",
      
    };
  cout<<"4. Set the vector-chain"<<endl;
  for (int i=0; i<Hist.size();i++){
    cout<<"5. Enter in FOR estructure"<<endl; 
      h=(TProfile*)f->Get("run_1/HLT/TauMon/Expert/"+Hist[i]+"/TurnOnCurves/RecoEfficiency/TProfRecoL1PtEfficiency");
    cout<<"6. Made the copy of the TProfile histogram"<<endl;
   
   //auto legend = new TLegend(0.1,0.7,0.48,0.9);
   //legend->SetHeader("The Legend Title","C");  option "C" allows to center the header
   //legend->AddEntry("f1","Function abs","l");
   //legend->Draw();
    
   cout<<"7. Set the legend of the histogram"<<endl;

      if (i>0){
      cout<<"8. Enter inside the if with i="<< i <<endl;   
      h->SetLineColor(i+2);
      cout<<"9. Set the color of the line number="<< i+2 <<endl;
      h->Draw("same");
      cout<<"10. Draw the histogram"<<endl; 
      gDirectory->cd("../../../");
      cout<<"11. Come back three directories"<<endl;
      gStyle->SetOptStat(0);
      cout<<"12. Removing statics box"<<endl;
    }
      else {
      cout<<"13. Enter to else with i="<< i <<endl;
      h->SetLineColor(i+2);
      cout<<"14. Set the color of the line number="<< i+2 <<endl;
      h->Draw();
      cout<<"15. Draw in else part"<<endl; 
      gDirectory->cd("../../../");
      cout<<"16. Come back three directories"<<endl;
      
    }

      
