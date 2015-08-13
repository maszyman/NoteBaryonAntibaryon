void plotcf(TString file1,TString histname1,TString pairType) {

  TFile* ifile1_ = new TFile(Form("%s",file1.Data()), "read");

  TH1D* hist1;

  
  hist1 = (TH1D*)ifile1_->Get(Form("%s",histname1.Data()));

  TCanvas *myCan = new TCanvas("asd","asd");
  myCan->Draw();
  myCan->cd();
  hist1->SetMarkerColor(kBlack);
  hist1->SetMarkerStyle(20);
  hist1->SetMarkerSize(1.6);
  hist1->SetTitle("");
  hist1->GetXaxis()->SetTitle("k* (GeV/c)");
  hist1->GetYaxis()->SetTitle("C(k*)");
  hist1->GetXaxis()->SetRangeUser(0.,1.0);
  gStyle->SetOptStat(0);
   hist1->SetMaximum(1.15);
  hist1->SetMinimum(0.91);
  hist1->Draw("lp");
  TLatex Tl;
  Tl.SetTextAlign(23);
  Tl.SetTextSize(0.08);
  Tl.SetTextColor(kBlack);
  Tl.DrawLatex(0.2,1.1,"Hijing 0-10%");
  Tl.DrawLatex(0.5,1.1,pairType.Data());

  myCan->SaveAs(Form("hijing%s.eps",pairType.Data()));
}
