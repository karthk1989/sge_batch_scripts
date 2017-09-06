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

// Bins, where det consists of only one horn polatiry  (i.e.  sk-fhc and sk-rhc are TWO seperate dets)
// **********************
det 1  low bin= 1   high bin= 80
det 2  low bin= 81   high bin= 160
det 3  low bin= 161   high bin= 240
det 4  low bin= 241   high bin= 320
det 5  low bin= 321   high bin= 400
det 6  low bin= 401   high bin= 480
det 7  low bin= 481   high bin= 560
det 8  low bin= 561   high bin= 640
det 9  low bin= 641   high bin= 720
det 10  low bin= 721   high bin= 800
det 11  low bin= 801   high bin= 880
det 12  low bin= 881   high bin= 960
det 13  low bin= 961   high bin= 1040
det 14  low bin= 1041   high bin= 1120
det 15  low bin= 1121   high bin= 1200
det 16  low bin= 1201   high bin= 1280
det 17  low bin= 1281   high bin= 1360
det 18  low bin= 1361   high bin= 1440
det 19  low bin= 1441   high bin= 1520
det 20  low bin= 1521   high bin= 1600
det 21  low bin= 1601   high bin= 1680
det 22  low bin= 1681   high bin= 1760
det 23  low bin= 1761   high bin= 1840
det 24  low bin= 1841   high bin= 1920
det 25  low bin= 1921   high bin= 2000
det 26  low bin= 2001   high bin= 2080
det 27  low bin= 2081   high bin= 2160
det 28  low bin= 2161   high bin= 2240
det 29  low bin= 2241   high bin= 2320
det 30  low bin= 2321   high bin= 2400


// Remiding myself of the obvious...
// bin = 0;       underflow bin
// bin = 1;       first bin with low-edge xlow INCLUDED
// bin = nbins;   last bin with upper-edge xup EXCLUDED
// bin = nbins+1; overflow bin



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
  TFile* TFcov = new TFile("./2_fvs__sk_nd5_nd2_nd9h7p7_hk2_hk3_hkk4_hkk5_prod_xsec_cov.root");
  TMatrixTSym<double>* matT = (TMatrixTSym<double>*) TFcov->Get("prod_xsec_cov");
//		std::cout<<" e = " << (*matT)[1][1] << std::endl;

	// --- XXX ---------------------- XXX--- ///		

    
  TMatrixDSym* cov = new TMatrixDSym(nRows);

  //TH2D (const char *name, const char *title, Int_t nRowsx, Double_t xlow, Double_t xup, Int_t nRowsy, Double_t ylow, Double_t yup)
  TH2D* h_cov = new TH2D("h_cov", "h_cov", nRows, 0, nRows, nRows, 0, nRows);

    double min=999.0 ;
    double max=-999.0 ;
    
    for( int irow = 0 ; irow< nRows ; irow++ ){
      for( int jcolumn = 0;  jcolumn< nRows; jcolumn++ ){

        double e =(*matT)[irow + binOffset][jcolumn + binOffset];

        (*cov)[irow][jcolumn] = e; 
	
	//  +1 because first histo bin is bin1  (bin0 is overlfow)
	h_cov->SetBinContent( irow+1, jcolumn+1, e );

        // std::cout<<" irow+1 = " << irow+1 << ", jcolumn+1 = " << jcolumn+1 <<",    element = " << e << std::endl;
	//if(e > 0.0085) std::cout<<" e > 0.0085:  e = " << e << ":  irow = " << irow << ", jcolumn = " << jcolumn << std::endl;
	//if(e < -0.002) std::cout<<" e < -0.002:  e = " << e << ":  irow = " << irow << ", jcolumn = " << jcolumn << std::endl;

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

	//double m = TMath::Max(h_cov->GetMaximum(),-h_cov->GetMinimum());
	//h_cov->GetZaxis()->SetRangeUser( min, max);
	//h_cov->GetZaxis()->SetRangeUser( -max, max);
	//h_cov->GetZaxis()->SetRangeUser( min, -min);
	//h_cov->GetZaxis()->SetRangeUser( 0.02, -0.02);
	//h_cov->GetZaxis()->SetRangeUser( -4, 4);

	Int_t nb = 5000;
	h_cov->SetContour(nb);
	h_cov->Draw("colz");
	c1->SaveAs("prod_xsec_cov_large.png");
	c1->SaveAs("prod_xsec_cov_large.pdf");
	c1->SaveAs("prod_xsec_cov_large.eps");


        TCanvas* c1_small = new TCanvas("prod_xsec_cov_small", "prod_xsec_cov_small", 1000, 1000);
        gPad->SetRightMargin(0.16);
        gStyle->SetOptStat(0);  // remove title
        gStyle->SetOptTitle(0); // remove stat box
        //gStyle->SetLegendBorderSize(0);       // remove border on legend
	h_cov->Draw("colz");
      	c1_small->SaveAs("prod_xsec_cov_small.png");
	c1_small->SaveAs("prod_xsec_cov_small.pdf");
	c1_small->SaveAs("prod_xsec_cov_small.eps");


        TCanvas* c2_small = new TCanvas("prod_xsec_cov_bins_0_320", "prod_xsec_cov_bins_0_320", 1000, 1000);
	gPad->SetRightMargin(0.16);
	gStyle->SetOptStat(0);	// remove title
	gStyle->SetOptTitle(0);	// remove stat box
	h_cov->GetXaxis()->SetRangeUser(0, 320);
	h_cov->GetYaxis()->SetRangeUser(0, 320);
	h_cov->Draw("colz");
        c2_small->SaveAs("prod_xsec_cov_0_320_small.png");
        c2_small->SaveAs("prod_xsec_cov_0_320_small.pdf");
        c2_small->SaveAs("prod_xsec_cov_0_320_small.eps");
	






  TH2D* h_corr = new TH2D("h_corr", "h_corr", nRows, 0, nRows, nRows, 0, nRows);

  // loop over the covariance matrix diagonal elements
  // cov_ii = var_i = (sig_i)^2
  // so uncorrelated error,  sig_i = sqrt( var(i) ) = sqrt{ cov_ii )

//std::cout<<"debug 1" << std::endl;

  double var[ nRows ];
  for( int irow=0; irow<nRows; irow++){

//std::cout<<"debug 2" << std::endl;

    // h_cov starts at bin1, array starts at element 0
    var[irow] = h_cov->GetBinContent( irow+1, irow+1 );

//std::cout<<"debug 3" << std::endl;
  }




  // loop over elements of cov to build the corr
  // corr_ik = cov_ik / (sig_i sig_k)  = cov_ik / sqrt(var_i var_k) = cov_ik / sqrt(cov_ii cov_kk)

  for( int irow=0; irow<nRows; irow++){
    for( int icol=0; icol<nRows; icol++){

//  std::cout<< "h_cov->GetBinContent( irow+1, irow+1 )  " << h_cov->GetBinContent( irow+1, irow+1 )  << std::endl;

       // h_cov starts at bin1, array starts at element 0     
      double numer = h_cov->GetBinContent( irow+1, icol+1 ) ;
      double denom = sqrt( var[irow]*var[icol] ); 

      double e_corr= numer / denom ;
      h_corr->SetBinContent( irow+1, icol+1 ,  e_corr );
    }
  }



  double matT_00 = (*matT)[ 0 ][ 0 ];
  double h_cov_11 = h_cov->GetBinContent( 0+1, 0+1 ); 
  double sig_00 = sqrt( var[0] );
  std::cout<<" From Matrix,  cov_00 = " << matT_00 << std::endl;
  std::cout<<" From 2d hist, cov_00 = " << h_cov_11 << std::endl;
  std::cout<<" sig_00 = sqrt( var_00 ) = sqrt( cov_00 )"<< sig_00 <<std::endl;
  std::cout<<""<<std::endl;
  std::cout<<"h_corr_00"<< h_corr->GetBinContent( 0+1, 0+1) << std::endl;
  std::cout<<""<<std::endl;
  std::cout<<""<<std::endl;

  double matT_10 = (*matT)[ 1 ][ 0 ];
  double h_cov_10 = h_cov->GetBinContent( 1+1, 0+1 ); 
  double sig_11 = sqrt( var[1] );
  //double sig_00 = sqrt( var[0] );

  std::cout<<" From Matrix,  cov_10 = " << matT_10 << std::endl;
  std::cout<<" From 2d hist, cov_10 = " << h_cov_10 << std::endl;
  std::cout<<" sig_00 = sqrt( var_0 ) = sqrt( cov_00 )"<< sig_00 <<std::endl;
  std::cout<<" sig_11 = sqrt( var_1 ) = sqrt( cov_11 )"<< sig_11 <<std::endl;
  std::cout<<""<<std::endl;
  std::cout<<"h_corr_10"<< h_corr->GetBinContent( 1+1, 0+1) << std::endl;
  std::cout<<""<<std::endl;

  TCanvas* c_corr_small = new TCanvas("prod_xsec_corr_small", "prod_xsec_corr_small", 1000, 1000);
  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);  // remove title
  gStyle->SetOptTitle(0); // remove stat box
  h_corr->Draw("colz");
  c_corr_small->SaveAs("prod_xsec_corr_small.png");
  c_corr_small->SaveAs("prod_xsec_corr_small.pdf");
  c_corr_small->SaveAs("prod_xsec_corr_small.eps");





// ND280   bin 161 (when numbered from 1) up to and including bin 240
//new

// 161 240

const int nBinsPerDet = 80;
const int nd5_lower = 161;
const int nd5_higher = 240;

  TH2D* h_corr_nd5_fhc = new TH2D("h_corr_nd5_fhc", "h_corr_nd5_fhc", nBinsPerDet, 0, nBinsPerDet, nBinsPerDet, 0, nBinsPerDet );

  for( int irow=0; irow<nBinsPerDet; irow++ ){
    for( int icol=0; icol<nBinsPerDet; icol++ ){

      double e_corr = h_corr->GetBinContent( nd5_lower + irow, nd5_lower + icol);
      //std::cout<<" irow="<<irow<<"  icol="<<icol << "    e_corr = " << e_corr  << std::endl;
      h_corr_nd5_fhc->SetBinContent( irow+1, icol+1, e_corr );
      
    }
  }




  TCanvas* c_corr_nd5_fhc = new TCanvas("c_corr_nd5_fhc", "c_corr_nd5_fhc", 1000, 1000);
  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);  // remove title
  gStyle->SetOptTitle(0); // remove stat box
  //double m = TMath::Max(h_corr_nd5_fhc->GetMaximum(),-h_corr_nd5_fhc->GetMinimum());
  //h_corr_nd5_fhc->GetZaxis()->SetRangeUser( min, max);
  //Int_t nb = 5000;
  h_corr_nd5_fhc->SetContour(nb);
  h_corr_nd5_fhc->Draw("colz");
  c_corr_nd5_fhc->SaveAs("corr_nd5_fhc.png");
  c_corr_nd5_fhc->SaveAs("corr_nd5_fhc.pdf");
  c_corr_nd5_fhc->SaveAs("corr_nd5_fhc.eps");



  // loop over the covariance matrix diagonal elements
  // cov_ii = var_i = (sig_i)^2
  // so uncorrelated error,  sig_i = sqrt( var(i) ) = sqrt{ cov_ii )

//std::cout<<"debug 1" << std::endl;

  double var_corr_nd5_fhc[ nBinsPerDet ];
  double err_corr_nd5_fhc[ nBinsPerDet ];

  for( int irow=0; irow<nBinsPerDet; irow++){

//std::cout<<"debug 2" << std::endl;

    // h_cov starts at bin1, array starts at element 0
    std::cout<<" h_cov ( " <<  irow + nd5_lower <<" ," <<  irow + nd5_lower  << " = " << h_cov->GetBinContent( irow + nd5_lower, irow + nd5_lower ) << std::endl;
    var_corr_nd5_fhc[irow] = h_cov->GetBinContent( irow + nd5_lower, irow + nd5_lower );
    err_corr_nd5_fhc[irow] = sqrt( var_corr_nd5_fhc[irow] );    
//std::cout<<"debug 3" << std::endl;
  }
  std::cout<<"dddbug1" <<std::endl;

  const int nBinsFlav=20;

  double err_corr_nd5_fhc_numu[ nBinsFlav ];
  std::cout<<"dddbug2" <<std::endl;
  TH1D* h_err_corr_nd5_fhc_numu = new TH1D("h_err_corr_nd5_fhc_numu", "h_err_corr_nd5_fhc_numu", nBinsFlav, 0, nBinsFlav);
  std::cout<<"dddbug3" <<std::endl;
  for( int irow=0; irow<20; irow++ ){
std::cout<<"@@@"<<std::endl;
    double err = err_corr_nd5_fhc[ 0 + irow ];
    err_corr_nd5_fhc_numu[irow] = err;
    h_err_corr_nd5_fhc_numu->SetBinContent( irow+1, err); 
  }
  std::cout<<"dddbug2" <<std::endl;

  double err_corr_nd5_fhc_anumu[ 20 ];
  TH1D* h_err_corr_nd5_fhc_anumu = new TH1D("h_err_corr_nd5_fhc_anumu", "h_err_corr_nd5_fhc_anumu", nBinsFlav, 0, nBinsFlav);
  for( int irow=0; irow<20; irow++ ){
    double err = err_corr_nd5_fhc[ 20 + irow ];
    err_corr_nd5_fhc_anumu[irow]=err;
    h_err_corr_nd5_fhc_anumu->SetBinContent( irow+1, err);
  }
  double err_corr_nd5_fhc_nue[ 20 ];
  TH1D* h_err_corr_nd5_fhc_nue = new TH1D("h_err_corr_nd5_fhc_nue", "h_err_corr_nd5_fhc_nue", nBinsFlav, 0, nBinsFlav);
  for( int irow=0; irow<20; irow++ ){
    double err = err_corr_nd5_fhc[ 40 + irow ];
    err_corr_nd5_fhc_nue[irow]=err;
    h_err_corr_nd5_fhc_nue->SetBinContent( irow+1, err);
  } 
  double err_corr_nd5_fhc_anue[ 20 ];
  TH1D* h_err_corr_nd5_fhc_anue = new TH1D("h_err_corr_nd5_fhc_anue", "h_err_corr_nd5_fhc_anue", nBinsFlav, 0, nBinsFlav);
  for( int irow=0; irow<20; irow++ ){
    double err = err_corr_nd5_fhc[ 60 + irow ];
    err_corr_nd5_fhc_anue[irow]=err;
    h_err_corr_nd5_fhc_anue->SetBinContent( irow+1, err);
  }

  TCanvas* c_err_nd5_fhc = new TCanvas("c_errr_nd5_fhc", "c_err_nd5_fhc", 1000, 1000);
  gStyle->SetLineWidth(2);
  h_err_corr_nd5_fhc_anue->SetLineColor(kCyan+1);
  h_err_corr_nd5_fhc_anue->SetLineWidth(2);
  h_err_corr_nd5_fhc_anue->Draw();
  h_err_corr_nd5_fhc_anue->GetYaxis()->SetRangeUser(0, 0.1); 
  h_err_corr_nd5_fhc_nue->SetLineColor(kBlue+1);
  h_err_corr_nd5_fhc_nue->Draw("SAME");
  h_err_corr_nd5_fhc_anumu->SetLineColor(kOrange+7);
  h_err_corr_nd5_fhc_anumu->Draw("SAME");
  h_err_corr_nd5_fhc_numu->SetLineColor(kRed+1);
  h_err_corr_nd5_fhc_numu->Draw("SAME");




}
