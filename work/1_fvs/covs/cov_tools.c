// soph.e.king123@gmail.com
// Some tools for manipulating matrices
// mainly for covariance, correlation and errors
// written for error_scripts syst calcs of flux



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// Header Section //////////////////////////////////////////////////////////////////////////////////////   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// Function definitions ////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




// TMatrixDSym* cov = new TMatrixDSym(nRows);
// (*cov)[irow][jcolumn] = e; 


// Takes a matrix of type TMatrixDSym and transform it into a TH2D histogram
// - elemet 0 of TMatrixDSym corresponds to Bin(1,1) of the TH2D

//****************************************************************************
void TMatrixTSym_to_TH2D( TMatrixTSym<double>& matT, int nRow,  int minRow=0, TH2D& return_h ){
//****************************************************************************
//****************************************************************************

  // note:  symmetric matrix --> nRow=nCol
  // To optimise time, could only loop over top triangle since it is symmetric
  // save to the heap to avoid memory leak

  //  TH2D h = TH2D("h", "h", nRow, 0, nRow, nRow, 0, nRow);
  for( int irow = minRow ; irow< nRow ; irow++ ){    
    for( int jcolumn = minRow;  jcolumn< nRow; jcolumn++ ){

      // read TMatrixTSym      
      double e =(matT)[irow + minRow][jcolumn + minRow];
      //std::cout<<"  - Bin(" << irow << ", " << jcolumn << ") = " << e << std::endl;

      //  +1 because first histo bin is bin1  (bin0 is overlfow)
      return_h.SetBinContent( irow+1, jcolumn+1, e );
    }
  }
  return ;//returnd_h;
}


// Read out the min and max bins of a TH2D histo

//****************************************************
void readOutMinMax_TH2D( TH2D& h, const int nRow, const int nCol ){
//****************************************************
 //****************************************************

  double min; int minRow, minCol;
  double max; int maxRow, maxCol;
 
  for( int irow = 0 ; irow< 8/*nRow*/; irow++ ){
    for( int jcol = 0;  jcol< nCol; jcol++ ){

      //  +1 because first histo bin is bin1  (bin0 is overlfow)
      double e = h.GetBinContent( irow+1, jcol+1 );
      //std::cout<<"  - Bin(" << irow << ", " << jcol << ") = " << e << std::endl;
 
      //if( irow == jcol == 0 )  min = max = e;

      if( e < min ){min = e; minRow = irow; minCol =jcol; }
      if( e > max ){max = e; maxRow = irow; maxCol =jcol; }

    }// jcolumn
  }// irow


  if( min && minRow && minCol ) std::cout<<"Min bin:  ("<< minRow <<", "<< minCol <<") = " << min << std::endl;
  else std::cout<<"No min found! " << std::endl;
  if( max && maxRow && maxCol ) std::cout<<"Max bin:  ("<< maxRow <<", "<< maxCol <<") = " << max << std::endl;
  else std::cout<<"No max found! " << std::endl;


  return;
}


// Return the min and max bins of a TH2D histo
// min, minRow, minCol, mac, macRow, maxCol, to be passsed by reference and filled
//****************************************************
void returnMinMax_TH2D( TH2D& h, int nRow, int nCol, int &min, int &minRow, int &minCol, int &max, int &maxRow, int &maxCol){
//****************************************************
//****************************************************
 
  for( int irow = 0 ; irow< nRow; irow++ ){
    for( int jcolumn = 0;  jcolumn< nCol; jcolumn++ ){

      //  +1 because first histo bin is bin1  (bin0 is overlfow)
      double e = h->GetBinContent( irow+1, jcolumn+1 );
  
      if( irow == jcolumn == 0 )  min = max = e;

      if( e < min ) {min = e; minRow = irow; minCol =jcol; }
      if( e > max ) {max = e; maxRow = irow; maxCol =jcol; }

    }// jcolumn
  }// irow


  if( min && minRow && minCol ) std::cout<<"Min bin:  ("<< minRow <<", "<< minCol <<") = " << min << std::endl;
  if( max && maxRow && maxCol ) std::cout<<"Max bin:  ("<< maxRow <<", "<< maxCol <<") = " << max << std::endl;
  return;
}



// Takes a TH2D

//****************************************************
void plot_TH2D_cov_default_cloz_large( TH2D& h_cov, std::string saveTag="", std::string saveLocation="$PWD", std::string title=""  ){
//****************************************************
//****************************************************


  const char* ch_title = title.c_str();

  if(saveLocation=="") saveLocation="$PWD";
  std::string save = saveLocation +"/"+ saveTag +"_cov_large";

  std::string save_png = save +".png";  const char* ch_save_png = save_png.c_str();
  std::string save_pdf = save +".pdf";  const char* ch_save_pdf = save_pdf.c_str();
  std::string save_eps = save +".eps";  const char* ch_save_eps = save_eps.c_str();

  std::string save_title_png = save +"_"+title+".png";  const char* ch_save_title_png = save_title_png.c_str();
  std::string save_title_pdf = save +"_"+title+".pdf";  const char* ch_save_title_pdf = save_title_pdf.c_str();
  std::string save_title_eps = save +"_"+title+".eps";  const char* ch_save_title_eps = save_title_eps.c_str();


  TCanvas* c2 = new TCanvas("c1", "c1", 4200, 4200);

  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);                 // remove stat box
  //gStyle->SetLegendBorderSize(0);      // remove border on legend

   /*const UInt_t Number = 5;
  Double_t Red[Number]    = { 1.00, 0.00, 0.00, 0.00, 0.00 };
  Double_t Green[Number]  = { 1.00, 0.80, 0.70, 0.20, 0.100 };
  Double_t Blue[Number]   = { 1.00, 0.80, 0.70, 0.20, 0.100 };
  Double_t Length[Number] = { 0.1, 0.3, 0.5, 0.70,  0.9 };
  Int_t nb = 50;
  TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,nb);
    */

  //double m = TMath::Max(h_cov->GetMaximum(),-h_cov->GetMinimum());
  //h_cov->GetZaxis()->SetRangeUser( min, max);
  //h_cov->GetZaxis()->SetRangeUser( -max, max);
  //h_cov->GetZaxis()->SetRangeUser( min, -min);
  //h_cov->GetZaxis()->SetRangeUser( 0.02, -0.02);
  //h_cov->GetZaxis()->SetRangeUser( -4, 4);

  h_cov->SetTitle( ch_title );

  Int_t nb = 5000;
  h_cov.SetContour(nb);
  h_cov.Draw("colz");

  c2->SaveAs(ch_save_title_png);
  c1->SaveAs(ch_save_title_pdf);
  c1->SaveAs(ch_save_title_eps);

  gStyle->SetOptTitle(0);                // remove title
  //gPad->Update();

  c1->SaveAs(ch_save_png);
  c1->SaveAs(ch_save_pdf);
  c1->SaveAs(ch_save_eps);

  delete c1;
  return;
} 




void plot_TH2D_cov_default_cloz_small( TH2D& h_cov, std::string saveTag="", std::string saveLocation="$PWD", std::string title=""  ){


  const char* ch_title = title.c_str();

  if(saveLocation=="") saveLocation="$PWD";
  std::string save = saveLocation +"/"+ saveTag +"_cov_small";

  std::string save_png = save +".png";  const char* ch_save_png = save_png.c_str();
  std::string save_pdf = save +".pdf";  const char* ch_save_pdf = save_pdf.c_str();
  std::string save_eps = save +".eps";  const char* ch_save_eps = save_eps.c_str();

  std::string save_title_png = save +"_"+title+".png";  const char* ch_save_title_png = save_title_png.c_str();
  std::string save_title_pdf = save +"_"+title+".pdf";  const char* ch_save_title_pdf = save_title_pdf.c_str();
  std::string save_title_eps = save +"_"+title+".eps";  const char* ch_save_title_eps = save_title_eps.c_str();


  TCanvas* c2 = new TCanvas("c1", "c1", 1000, 1000);

  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);                 // remove stat box
  //gStyle->SetLegendBorderSize(0);      // remove border on legend

   /*const UInt_t Number = 5;
  Double_t Red[Number]    = { 1.00, 0.00, 0.00, 0.00, 0.00 };
  Double_t Green[Number]  = { 1.00, 0.80, 0.70, 0.20, 0.100 };
  Double_t Blue[Number]   = { 1.00, 0.80, 0.70, 0.20, 0.100 };
  Double_t Length[Number] = { 0.1, 0.3, 0.5, 0.70,  0.9 };
  Int_t nb = 50;
  TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,nb);
    */

  //double m = TMath::Max(h_cov->GetMaximum(),-h_cov->GetMinimum());
  //h_cov->GetZaxis()->SetRangeUser( min, max);
  //h_cov->GetZaxis()->SetRangeUser( -max, max);
  //h_cov->GetZaxis()->SetRangeUser( min, -min);
  //h_cov->GetZaxis()->SetRangeUser( 0.02, -0.02);
  //h_cov->GetZaxis()->SetRangeUser( -4, 4);

  h_cov->SetTitle( ch_title );

  Int_t nb = 5000;
  h_cov.SetContour(nb);
  h_cov.Draw("colz");

  c2->SaveAs(ch_save_title_png);
  c1->SaveAs(ch_save_title_pdf);
  c1->SaveAs(ch_save_title_eps);

  gStyle->SetOptTitle(0);                // remove title
  //gPad->Update();

  c1->SaveAs(ch_save_png);
  c1->SaveAs(ch_save_pdf);
  c1->SaveAs(ch_save_eps);

  delete c1;
  return;
}









 
// Not that histo bin numbered from 1 upwards
void plot_TH2D_cov_default_cloz_large_cutOut( TH2D& h_cov, std::string saveTag="", std::string saveLocation="$PWD", std::string title="", int histMin0=0, int histMaxNminus1=1  ){


  const char* ch_title = title.c_str();

  if(saveLocation=="") saveLocation="$PWD";
  std::string save = saveLocation +"/"+ saveTag +"_cov_large_cutOut";

  std::string save_png = save +".png";  const char* ch_save_png = save_png.c_str();
  std::string save_pdf = save +".pdf";  const char* ch_save_pdf = save_pdf.c_str();
  std::string save_eps = save +".eps";  const char* ch_save_eps = save_eps.c_str();

  std::string save_title_png = save +"_title.png";  const char* ch_save_title_png = save_title_png.c_str();
  std::string save_title_pdf = save +"_title.pdf";  const char* ch_save_title_pdf = save_title_pdf.c_str();
  std::string save_title_eps = save +"_title.eps";  const char* ch_save_title_eps = save_title_eps.c_str();


  TCanvas* c2 = new TCanvas("c1", "c1", 4200, 4200);

  gPad->SetRightMargin(0.16);
  gStyle->SetOptStat(0);                 // remove stat box
  //gStyle->SetLegendBorderSize(0);      // remove border on legend

   /*const UInt_t Number = 5;
  Double_t Red[Number]    = { 1.00, 0.00, 0.00, 0.00, 0.00 };
  Double_t Green[Number]  = { 1.00, 0.80, 0.70, 0.20, 0.100 };
  Double_t Blue[Number]   = { 1.00, 0.80, 0.70, 0.20, 0.100 };
  Double_t Length[Number] = { 0.1, 0.3, 0.5, 0.70,  0.9 };
  Int_t nb = 50;
  TColor::CreateGradientColorTable(Number,Length,Red,Green,Blue,nb);
    */

  //double m = TMath::Max(h_cov->GetMaximum(),-h_cov->GetMinimum());
  //h_cov->GetZaxis()->SetRangeUser( min, max);
  //h_cov->GetZaxis()->SetRangeUser( -max, max);
  //h_cov->GetZaxis()->SetRangeUser( min, -min);
  //h_cov->GetZaxis()->SetRangeUser( 0.02, -0.02);
  //h_cov->GetZaxis()->SetRangeUser( -4, 4);

  h_cov->SetTitle( ch_title );

  h_cov->GetXaxis()->SetRangeUser(histMin0, histMaxNminus1);
  h_cov->GetYaxis()->SetRangeUser(histMin0, histMaxNminus1);

  Int_t nb = 5000;
  h_cov.SetContour(nb);
  h_cov.Draw("colz");

  c2->SaveAs(ch_save_title_png);
  c1->SaveAs(ch_save_title_pdf);
  c1->SaveAs(ch_save_title_eps);

  gStyle->SetOptTitle(0);                // remove title
  //gPad->Update();

  c1->SaveAs(ch_save_png);
  c1->SaveAs(ch_save_pdf);
  c1->SaveAs(ch_save_eps);

  delete c1;
  return;
} 


// Not that histo bin numbered from 1 upwards
double extractArrayDaigCov_var( TH2D& h_cov, int nRrows){

  const int nRowsConst = nRows;
  double var[ nRows ];
  for( int irow=0; irow<nRowsConst; irow++){

    // h_cov starts at bin1, array starts at element 0
    var[irow] = h_cov->GetBinContent( irow+1, irow+1 );
  }

  return var;
}







  ////////////////////////////////////////////////////////////////////////
  ////////////// Build and plot the full correlations matrix  /////////////


  // loop over the covariance matrix diagonal elements
  // cov_ii = var_i = (sig_i)^2
  // so uncorrelated error,  sig_i = sqrt( var(i) ) = sqrt{ cov_ii )


/// take a cov, extract the var from the diag, and form the correlation matrix

void builCorFromCov = new TH2D( TH2D& h_cov, int nRows, TH2D& outCor ){

  double var = extracArrayDaigCov_var( TH2D& h_cov, int nRrows);


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



}













