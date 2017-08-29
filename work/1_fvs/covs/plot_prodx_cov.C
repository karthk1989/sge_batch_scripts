// Bin1 = det1, flavour1(numu), bin1
// Bin2 = det1, flavour1(numu), bin2
// ...
// Bin x = det1, flavour2(numubar), bin1
// Bin y = det1, flavour2(numubar), bin2
// ... 
// ...
// Bin z = det2, flavour1(numu), bin1

// Each det has 20*4=80 bins per horn polarity

// skfhc, skrhc, hk2fhc, hk2rhc, nd280baskfhc, nd280baskrhc, IWCD

// note - cov bins labeled from 0-(N-1)
//      - histo bins labeled from 1-N

// 2D histo - config A //
// **********************
// sk     -fhc	(1,80),    	sk     -rhc	(81-160)
// nd280  -fhc	(161,240), 	hk     -rhc	(241-320)
// IWCD-1 -fhc	(321,400), 	nd280  -rhc	(401, 480)
// IWCD-2 -fhc	(481,560), 	IWCD-1 -rhc	(561,640)
//
//
// hk

{	

  // --- XXX --- THINGS TO EDIT --- XXX --- ///
	
  const int nbins = 20;
  const int ndets = (1+1+1+7)*2 ;
  const int nflavours = 4;

  bool setMin = false;   const int binMin = 0;
  bool setMax = false;   const int binMax = 0;
  const int binOffset = 0;
  
  const int nRows =  nflavours* nbins * ndets ;
  std::cout<<" nRows = " << nRows << std::endl;
			

 
  TFile* TFcov = new TFile("./1_fvs__sk_hk2_nd5_nd9h10__prod_xsec_cov.root");
  TMatrixTSym<double>* matT = (TMatrixTSym<double>*) TFcov->Get("prod_xsec_cov");
//		std::cout<<" e = " << (*matT)[1][1] << std::endl;

	// --- XXX ---------------------- XXX--- ///		

    
  TMatrixDSym* cov = new TMatrixDSym(nRows);

  //TH2D (const char *name, const char *title, Int_t nRowsx, Double_t xlow, Double_t xup, Int_t nRowsy, Double_t ylow, Double_t yup)
  TH2D* hist = new TH2D("hist", "hist", nRows, 0, nRows, nRows, 0, nRows);

    double min=999.0 ;
    double max=-999.0 ;
    
    for( int irow = 0 ; irow< nRows ; irow++ ){
      for( int jcolumn = 0;  jcolumn< nRows; jcolumn++ ){

        double e =(*matT)[irow + binOffset][jcolumn + binOffset];

        (*cov)[irow][jcolumn] = e; 
	
	//  +1 because first histo bin is bin1  (bin0 is overlfow)
	hist->SetBinContent( irow+1, jcolumn+1, e );

        // std::cout<<" irow+1 = " << irow+1 << ", jcolumn+1 = " << jcolumn+1 <<",    element = " << e << std::endl;
	if(e > 0.0085) std::cout<<" e > 0.0085:  e = " << e << ":  irow = " << irow << ", jcolumn = " << jcolumn << std::endl;
	if(e < -0.002) std::cout<<" e < -0.002:  e = " << e << ":  irow = " << irow << ", jcolumn = " << jcolumn << std::endl;

        if( e < min ) min =e;
        if( e > max ) max =e;
      }
    }
  std::cout<<" min = " << min <<std::endl;
  std::cout<<" max = " << max <<std::endl;
  std::cout<<" nRows = " << nRows << std::endl;
 
	// doesn't work
	//new TCanvas;
	//matT->Draw("");
	//return 0;
	
	// doesn't work
	//new TCanvas;
	//cov->Draw("");
	//return 0;		


	/*const UInt_t Number = 5;
	Double_t Red[Number]    = { 1.00, 0.00, 0.00, 0.00, 0.00 };
	Double_t Green[Number]  = { 1.00, 0.80, 0.70, 0.20, 0.100 };
	Double_t Blue[Number]   = { 1.00, 0.80, 0.70, 0.20, 0.100 };
	Double_t Length[Number] = { 0.1, 0.3, 0.5, 0.70,  0.9 };
	Int_t nb = 50;
	TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,nb);
	  */

	TCanvas* c1 = new TCanvas("prod_xsec_cov_large", "prod_xsec_cov_large", 4200, 4200);
	gPad->SetRightMargin(0.16);
	gStyle->SetOptStat(0);	// remove title
	gStyle->SetOptTitle(0);	// remove stat box
	//gStyle->SetLegendBorderSize(0); 	// remove border on legend

	//double m = TMath::Max(hist->GetMaximum(),-hist->GetMinimum());
	//hist->GetZaxis()->SetRangeUser( min, max);
	//hist->GetZaxis()->SetRangeUser( -max, max);
	//hist->GetZaxis()->SetRangeUser( min, -min);
	//hist->GetZaxis()->SetRangeUser( 0.02, -0.02);
	//hist->GetZaxis()->SetRangeUser( -4, 4);

	Int_t nb = 5000;
	hist->SetContour(nb);
	hist->Draw("colz");
	c1->SaveAs("prod_xsec_cov_large.png");
	c1->SaveAs("prod_xsec_cov_large.pdf");
	c1->SaveAs("prod_xsec_cov_large.eps");

        TCanvas* c1_small = new TCanvas("prod_xsec_cov_small", "prod_xsec_cov_small", 1000, 1000);
        gPad->SetRightMargin(0.16);
        gStyle->SetOptStat(0);  // remove title
        gStyle->SetOptTitle(0); // remove stat box
        //gStyle->SetLegendBorderSize(0);       // remove border on legend
	hist->Draw("colz");
      	c1_small->SaveAs("prod_xsec_cov_small.png");
	c1_small->SaveAs("prod_xsec_cov_small.pdf");
	c1_small->SaveAs("prod_xsec_cov_small.eps");


	


        TCanvas* c2 = new TCanvas("prod_xsec_cov_bins_0_320", "prod_xsec_cov_bins_0_320", 1000, 1000);;
	gPad->SetRightMargin(0.16);
	gStyle->SetOptStat(0);	// remove title
	gStyle->SetOptTitle(0);	// remove stat box
	hist->GetXaxis()->SetRangeUser(0, 320);
	hist->GetYaxis()->SetRangeUser(0, 320);
	hist->Draw("colz");
	

}
