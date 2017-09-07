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


// Remiding myself of the obvious...
// bin = 0;       underflow bin
// bin = 1;       first bin with low-edge xlow INCLUDED
// bin = nbins;   last bin with upper-edge xup EXCLUDED
// bin = nbins+1; overflow bin



int plot_prodx_cov(){	

  // --- XXX --- THINGS TO EDIT --- XXX --- ///
	
  const int nbins = 20;
  const int ndets = (1+1+1+7)*2 ;
  const int nflavours = 4;
  const int nBinsPerDet = nbins*nflavours;

  bool setMin = false;   const int binMin = 0;
  bool setMax = false;   const int binMax = 0;
  const int binOffset = 0;
  
  const int nRows =  nflavours* nbins * ndets ;
  std::cout<<" nRows = " << nRows << std::endl;
			
  std::string str_syst = "prod_xsec";
 
  TFile* TFcov = new TFile("./1_fvs__sk_hk2_nd5_nd9h10__prod_xsec_cov.root");
  TFile* TFcov = new TFile("./2_fvs__sk_nd5_nd2_nd9h7p7_hk2_hk3_hkk4_hkk5_prod_xsec_cov.root");
  TMatrixTSym<double>* matT = (TMatrixTSym<double>*) TFcov->Get("prod_xsec_cov");
//		std::cout<<" e = " << (*matT)[1][1] << std::endl;

	// --- XXX ---------------------- XXX--- ///		


const int det_1_lowBin=1;      const int det_1_highBin=80;  //     numu=1-20, anumu=21-40, nue=41-60, anue=61-80
const int det_2_lowBin=81;     const int det_2_highBin=160;  //    numu=81-100, anumu=101-120, nue=121-140, anue=141-160
const int det_3_lowBin=161;    const int det_3_highBin=240;  //    numu=161-180, anumu=181-200, nue=201-220, anue=221-240
const int det_4_lowBin=241;    const int det_4_highBin=320;  //    numu=241-260, anumu=261-280, nue=281-300, anue=301-320
const int det_5_lowBin=321;    const int det_5_highBin=400;  //    numu=321-340, anumu=341-360, nue=361-380, anue=381-400
const int det_6_lowBin=401;    const int det_6_highBin=480;  //    numu=401-420, anumu=421-440, nue=441-460, anue=461-480
const int det_7_lowBin=481;    const int det_7_highBin=560;  //    numu=481-500, anumu=501-520, nue=521-540, anue=541-560
const int det_8_lowBin=561;    const int det_8_highBin=640;  //    numu=561-580, anumu=581-600, nue=601-620, anue=621-640
const int det_9_lowBin=641;    const int det_9_highBin=720;  //    numu=641-660, anumu=661-680, nue=681-700, anue=701-720
const int det_10_lowBin=721;   const int det_10_highBin=800;  //   numu=721-740, anumu=741-760, nue=761-780, anue=781-800
const int det_11_lowBin=801;   const int det_11_highBin=880;  //   numu=801-820, anumu=821-840, nue=841-860, anue=861-880
const int det_12_lowBin=881;   const int det_12_highBin=960;  //   numu=881-900, anumu=901-920, nue=921-940, anue=941-960
const int det_13_lowBin=961;   const int det_13_highBin=1040;  //  numu=961-980, anumu=981-1000, nue=1001-1020, anue=1021-1040
const int det_14_lowBin=1041;  const int det_14_highBin=1120;  //  numu=1041-1060, anumu=1061-1080, nue=1081-1100, anue=1101-1120
const int det_15_lowBin=1121;  const int det_15_highBin=1200;  //  numu=1121-1140, anumu=1141-1160, nue=1161-1180, anue=1181-1200
const int det_16_lowBin=1201;  const int det_16_highBin=1280;  //  numu=1201-1220, anumu=1221-1240, nue=1241-1260, anue=1261-1280
const int det_17_lowBin=1281;  const int det_17_highBin=1360;  //  numu=1281-1300, anumu=1301-1320, nue=1321-1340, anue=1341-1360
const int det_18_lowBin=1361;  const int det_18_highBin=1440;  //  numu=1361-1380, anumu=1381-1400, nue=1401-1420, anue=1421-1440
const int det_19_lowBin=1441;  const int det_19_highBin=1520;  //  numu=1441-1460, anumu=1461-1480, nue=1481-1500, anue=1501-1520
const int det_20_lowBin=1521;  const int det_20_highBin=1600;  //  numu=1521-1540, anumu=1541-1560, nue=1561-1580, anue=1581-1600
const int det_21_lowBin=1601;  const int det_21_highBin=1680;  //  numu=1601-1620, anumu=1621-1640, nue=1641-1660, anue=1661-1680
const int det_22_lowBin=1681;  const int det_22_highBin=1760;  //  numu=1681-1700, anumu=1701-1720, nue=1721-1740, anue=1741-1760
const int det_23_lowBin=1761;  const int det_23_highBin=1840;  //  numu=1761-1780, anumu=1781-1800, nue=1801-1820, anue=1821-1840
const int det_24_lowBin=1841;  const int det_24_highBin=1920;  //  numu=1841-1860, anumu=1861-1880, nue=1881-1900, anue=1901-1920
const int det_25_lowBin=1921;  const int det_25_highBin=2000;  //  numu=1921-1940, anumu=1941-1960, nue=1961-1980, anue=1981-2000
const int det_26_lowBin=2001;  const int det_26_highBin=2080;  //  numu=2001-2020, anumu=2021-2040, nue=2041-2060, anue=2061-2080
const int det_27_lowBin=2081;  const int det_27_highBin=2160;  //  numu=2081-2100, anumu=2101-2120, nue=2121-2140, anue=2141-2160
const int det_28_lowBin=2161;  const int det_28_highBin=2240;  //  numu=2161-2180, anumu=2181-2200, nue=2201-2220, anue=2221-2240
const int det_29_lowBin=2241;  const int det_29_highBin=2320;  //  numu=2241-2260, anumu=2261-2280, nue=2281-2300, anue=2301-2320
const int det_30_lowBin=2321;  const int det_30_highBin=2400;  //  numu=2321-2340, anumu=2341-2360, nue=2361-2380, anue=2381-2400





////////////////////////////////////////////////////////////////////////
///////////////// Retrieving and plotting the full cov /////////////////

    
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
	


 ////////////////////////////////////////////////////////////////////////
////////////// Build and plot the full correlations matrix  /////////////


  // loop over the covariance matrix diagonal elements
  // cov_ii = var_i = (sig_i)^2
  // so uncorrelated error,  sig_i = sqrt( var(i) ) = sqrt{ cov_ii )

  double var[ nRows ];
  for( int irow=0; irow<nRows; irow++){

    // h_cov starts at bin1, array starts at element 0
    var[irow] = h_cov->GetBinContent( irow+1, irow+1 );
  }



  TH2D* h_corr = new TH2D("h_corr", "h_corr", nRows, 0, nRows, nRows, 0, nRows);

  // loop over elements of cov to build the corr
  // corr_ik = cov_ik / (sig_i sig_k)  = cov_ik / sqrt(var_i var_k) = cov_ik / sqrt(cov_ii cov_kk)

  for( int irow=0; irow<nRows; irow++){
    for( int icol=0; icol<nRows; icol++){
      
       // h_cov starts at bin1, array starts at element 0     
      double numer = h_cov->GetBinContent( irow+1, icol+1 ) ;
      double denom = sqrt( var[irow]*var[icol] ); 
      double e_corr= numer / denom ;
      h_corr->SetBinContent( irow+1, icol+1 ,  e_corr );
    }
  }

  
  // sanity checks

  std::cout<<""<<std::endl;
  std::cout<<"  Perform sanity check " << std::endl;
  std::cout<<""<<std::endl;

  double matT_00 = (*matT)[ 0 ][ 0 ];
  double h_cov_11 = h_cov->GetBinContent( 0+1, 0+1 ); 
  double sig_00 = sqrt( var[0] );
  std::cout<<" From Matrix,  cov_00 = " << matT_00 << std::endl;
  std::cout<<" From 2d hist, cov_00 = " << h_cov_11 << std::endl;
  std::cout<<" sig_00 = sqrt( var_00 ) = sqrt( cov_00 ) = "<< sig_00 <<std::endl;
  std::cout<<""<<std::endl;
  std::cout<<"h_corr_00 = "<< h_corr->GetBinContent( 0+1, 0+1) << std::endl;
  std::cout<<""<<std::endl;
  std::cout<<""<<std::endl;

  double matT_10 = (*matT)[ 1 ][ 0 ];
  double h_cov_10 = h_cov->GetBinContent( 1+1, 0+1 ); 
  double sig_11 = sqrt( var[1] );
  //double sig_00 = sqrt( var[0] );

  std::cout<<" From Matrix,  cov_10 = " << matT_10 << std::endl;
  std::cout<<" From 2d hist, cov_10 = " << h_cov_10 << std::endl;
  std::cout<<" sig_00 = sqrt( var_0 ) = sqrt( cov_00 ) = "<< sig_00 <<std::endl;
  std::cout<<" sig_11 = sqrt( var_1 ) = sqrt( cov_11 ) = "<< sig_11 <<std::endl;
  std::cout<<""<<std::endl;
  std::cout<<"h_corr_10 = "<< h_corr->GetBinContent( 1+1, 0+1) << std::endl;
  std::cout<<""<<std::endl;
  std::cout<<""<<std::endl;

  
  // Plot full correlation matrix

  TCanvas* c_corr_small = new TCanvas("prod_xsec_corr_small", "prod_xsec_corr_small", 1000, 1000);
  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);  // remove title
  gStyle->SetOptTitle(0); // remove stat box
  h_corr->Draw("colz");
  c_corr_small->SaveAs("prod_xsec_corr_small.png");
  c_corr_small->SaveAs("prod_xsec_corr_small.pdf");
  c_corr_small->SaveAs("prod_xsec_corr_small.eps");








  ///////////////////////////////////////////////////////////////
  ///// Cut out det matrices from the full correlation matrix ////

  //TH2D* h_corr_det = new TH2D("h_corr_det", "h_corr_det", nBinsPerDet, 0, nBinsPerDet, nBinsPerDet, 0, nBinsPerDet );
  //TH2D h_corr_det = T2HD("h_corr_det", "h_corr_det", nBinsPerDet, 0, nBinsPerDet, nBinsPerDet, 0, nBinsPerDet );
  std::string str_det_1 = "1_sk_fhc";
  int det1_corr = cutOutDet_corr(  h_corr, det_1_lowBin,  det_1_highBin,  nBinsPerDet,  str_det_1, str_syst );
  int det1_err = getErrosFromCov( h_cov,  det_1_lowBin, det_1_highBin,  nBinsPerDet,  str_det_1 , str_syst );

  std::string str_det_2 = "1_sk_rhc";
  int det2_corr = cutOutDet_corr(  h_corr, det_2_lowBin,  det_2_highBin,  nBinsPerDet,  str_det_2, str_syst );
  int det2_err = getErrosFromCov( h_cov,  det_2_lowBin, det_2_highBin,  nBinsPerDet,  str_det_2 , str_syst );



/*

// ND280   bin 161 (when numbered from 1) up to and including bin 240
//new

// 161 240

//const int nBinsPerDet = 80;
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

*/




exit();

  // loop over the covariance matrix diagonal elements
  // cov_ii = var_i = (sig_i)^2
  // so uncorrelated error,  sig_i = sqrt( var(i) ) = sqrt{ cov_ii )

//std::cout<<"debug 1" << std::endl;


/*


  double var_corr_nd5_fhc[ nBinsPerDet ];
  double err_corr_nd5_fhc[ nBinsPerDet ];

  for( int irow=0; irow<nBinsPerDet; irow++){

    // h_cov starts at bin1, array starts at element 0
    std::cout<<" h_cov ( " <<  irow + nd5_lower <<" ," <<  irow + nd5_lower  << " = " <<
      h_cov->GetBinContent( irow + nd5_lower, irow + nd5_lower ) << std::endl;
    
    var_corr_nd5_fhc[irow] = h_cov->GetBinContent( irow + nd5_lower, irow + nd5_lower );
    err_corr_nd5_fhc[irow] = sqrt( var_corr_nd5_fhc[irow] );    
  }

  const int nBinsFlav=20;

  double err_corr_nd5_fhc_numu[ nBinsFlav ];
  TH1D* h_err_corr_nd5_fhc_numu = new TH1D("h_err_corr_nd5_fhc_numu", "h_err_corr_nd5_fhc_numu", nBinsFlav, 0, nBinsFlav);

  for( int irow=0; irow<20; irow++ ){
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


int what(){
  std::cout<<" aghhhh " << std::endl;
  return 4;
}

*/




int cutOutDet_corr( TH2D* h_corr,  const int lowBin, const int highBin, const int nBinsPerDet, std::string str_det, std::string str_syst ){

  int lb=lowBin, hb=highBin;

  TH2D* h_corr_det = new TH2D("h_corr_det", "h_corr_det", nBinsPerDet, 0, nBinsPerDet, nBinsPerDet, 0, nBinsPerDet );

  std::cout<<" Retriving detector corr from full corr matrix " << std::endl;
  for( int irow=0; irow<nBinsPerDet; irow++ ){
    for( int icol=0; icol<nBinsPerDet; icol++ ){
      std::cout<<" inside function      h_corr->GetBinConent(2,2) = " <<  h_corr->GetBinContent(2,2) << std::endl;

     int row = irow + lb;
     int col = icol + lb;
     double e_corr = h_corr->GetBinContent( row, col);
     std::cout<<" row="<<row<< ", col=" << col << "    e_corr = " << e_corr  << std::endl;
     h_corr_det->SetBinContent( irow+1, icol+1, e_corr );
      
    }
  }


  TCanvas* c_corr_det = new TCanvas("c_corr_nd5_fhc", "c_corr_nd5_fhc", 1000, 1000);
  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);  // remove title
  gStyle->SetOptTitle(0); // remove stat box
  //double m = TMath::Max(h_corr_nd5_fhc->GetMaximum(),-h_corr_nd5_fhc->GetMinimum());
  //h_corr_nd5_fhc->GetZaxis()->SetRangeUser( min, max);
  Int_t nb = 5000;
  h_corr_det->SetContour(nb);
  h_corr_det->Draw("colz");


  
  std::string str_save_det_syst = str_det +"_"+ str_syst;

  std::string str_save_det_syst_png = str_det +"_"+ str_syst +".png";
  std::string str_save_det_syst_pdf = str_det +"_"+ str_syst +".pdf";
  std::string str_save_det_syst_eps = str_det +"_"+ str_syst +".eps";

  const char* save_det_syst_png = str_save_det_syst_png.c_str();
  const char* save_det_syst_pdf = str_save_det_syst_pdf.c_str();
  const char* save_det_syst_eps = str_save_det_syst_eps.c_str();

  c_corr_det->SaveAs(save_det_syst_png);
  c_corr_det->SaveAs(save_det_syst_pdf);
  c_corr_det->SaveAs(save_det_syst_eps);

std::cout<<" saving" << std::endl;



  return 0;

}




int getErrosFromCov( TH2D* h_cov,  const int lowBin, const int highBin, const int nBinsPerDet, std::string str_det, std::string str_syst ){

  int lb=lowBin, hb=highBin;

  //////// Retrieving the errors from diag of full cov ///////
  std::cout<<" --- Retrieving the errors from diag of full cov --- " << std::endl;


  double var_det[ nBinsPerDet ];
  double err_corr_nd5_fhc[ nBinsPerDet ];

  for( int irow=0; irow<nBinsPerDet; irow++){

    // h_cov starts at bin1, array starts at element 0
    std::cout<<" h_cov ( " <<  irow + lowBin <<" ," <<  irow + lowBin  << " = " <<
      h_cov->GetBinContent( irow + lowBin, irow + lowBin ) << std::endl;
    
    var_det[irow] = h_cov->GetBinContent( irow + lowBin, irow + lowBin );
    err_corr_nd5_fhc[irow] = sqrt( var_det[irow] );    
  }

  const int nBinsFlav=20;

  double err_corr_nd5_fhc_numu[ nBinsFlav ];
  TH1D* h_err_corr_nd5_fhc_numu = new TH1D("h_err_corr_nd5_fhc_numu", "h_err_corr_nd5_fhc_numu", nBinsFlav, 0, nBinsFlav);

  for( int irow=0; irow<20; irow++ ){
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



  
  //std::string str_save_det_syst = str_det +"_"+ str_syst +"_errs";

  std::string str_save_det_syst_png = str_det +"_"+ str_syst +"_errs.png";
  std::string str_save_det_syst_pdf = str_det +"_"+ str_syst +"_errs.pdf";
  std::string str_save_det_syst_eps = str_det +"_"+ str_syst +"_errs.eps";

  const char* save_det_syst_png = str_save_det_syst_png.c_str();
  const char* save_det_syst_pdf = str_save_det_syst_pdf.c_str();
  const char* save_det_syst_eps = str_save_det_syst_eps.c_str();

  c_err_nd5_fhc->SaveAs(save_det_syst_png);
  c_err_nd5_fhc->SaveAs(save_det_syst_pdf);
  c_err_nd5_fhc->SaveAs(save_det_syst_eps);


std::cout<<" saving" << std::endl;

c_err_nd5_fhc->SaveAs("fuck.png");
  return 0;
}


