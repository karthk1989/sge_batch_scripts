// Bin1 = det1, flavour1(numu), bin1
// Bin2 = det1, flavour1(numu), bin2
// ...
// Bin x = det1, flavour2(numubar), bin1
// Bin y = det1, flavour2(numubar), bin2
// ... 
// ...
// Bin z = det2, flavour1(numu), bin1

// Each det has 20*4=80 bins per horn polarity

// skfhc, skrhc, hk2fhc, hk2rhc, nd280baskfhc, nd280baskrhc, e61

// note - cov bins labeled from 0-(N-1)
//      - histo bins labeled from 1-N
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
			
		//const int nRows = 2240;
		//const int binOffset = 0;
		
		//const int nRows = 800;   
		//const int binOffset = 0;
		
		//const int nRows = 1440; 
		//const int binOffset = 800; 
		

		
	// far dets:   4 * 20 * 5*2 = 800
	// near dets:  4 * 20 * 9*2 = 1440
 
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

        std::cout<<" irow+1 = " << irow+1 << ", jcolumn+1 = " << jcolumn+1 <<",    element = " << e << std::endl;
	//if(e > 0.0085) std::cout<<" e > 0.0085:  e = " << e << ":  irow = " << irow << ", jcolumn = " << jcolumn << std::endl;
	//if(e < -0.0018) std::cout<<" e < -0.018:  e = " << e << ":  irow = " << irow << ", jcolumn = " << jcolumn << std::endl;

        if( e < min ) min =e;
        if( e > max ) max =e;
      }
    }
  std::cout<<" min = " << min <<std::endl;
  std::cout<<" max = " << max <<std::endl;

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

	TCanvas* c1 = new TCanvas;
	gPad->SetRightMargin(0.15);
	gStyle->SetOptStat(0);	// remove title
	gStyle->SetOptTitle(0);	// remove stat box
	//gStyle->SetLegendBorderSize(0); 	// remove border on legend

	//double m = TMath::Max(hist->GetMaximum(),-hist->GetMinimum());
	//hist->GetZaxis()->SetRangeUser(0.0007, 0.0009);
	
	//hist->GetZaxis()->SetRangeUser( min, max);
	//hist->GetZaxis()->SetRangeUser( -max, max);
	//hist->GetZaxis()->SetRangeUser( min, -min);
	//hist->GetZaxis()->SetRangeUser( 0.02, -0.02);
	//hist->GetZaxis()->SetRangeUser( -4, 4);
	
	//hist->GetXaxis()->SetRangeUser(0, 10);
	//hist->GetYaxis()->SetRangeUser(-1,1);
	Int_t nb = 5000;
	 hist->SetContour(nb);

	hist->Draw("colz");
	c1->SaveAs("prod_xsec_cov.png");
	//c1->SaveAs("na61_cov_farDets_50throw_(min,max).png");
	//c1->SaveAs("na61_cov_nearDets_50throw_(min,max).png");.ls
	

	TCanvas* c2 = new TCanvas;
	gPad->SetRightMargin(0.15);
	gStyle->SetOptStat(0);	// remove title
	gStyle->SetOptTitle(0);	// remove stat box
	hist->GetXaxis()->SetRangeUser(0, 800);
	hist->GetYaxis()->SetRangeUser(0, 800);
	hist->Draw("colz");
	

}
