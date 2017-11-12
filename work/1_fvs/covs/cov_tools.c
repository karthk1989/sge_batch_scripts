// soph.e.king123@gmail.com
// Some tools for manipulating matrices
// mainly for covariance, correlation and errors
// written for error_scripts syst calcs of flux



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// Header Section //////////////////////////////////////////////////////////////////////////////////////   
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// Takes a matrix of type TMatrixDSym and transform it into a TH2D histogram
// - elemet 0 of TMatrixDSym corresponds to Bin(1,1) of the TH2D

//****************************************************************************
TH2D h_cov = TMatrixTSym_to_TH2D( TMatrixTSym matT, int nRows, int minRow=0 )
//****************************************************************************


// Read out the min and max bins of a TH2D histo

//****************************************************
void readOutMinMax_TH2D( TH2D h, int nRows, int nCol ){
//****************************************************
 


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////// Function definitions ////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



// Takes a matrix of type TMatrixDSym and transform it into a TH2D histogram
// - elemet 0 of TMatrixDSym corresponds to Bin(1,1) of the TH2D

//****************************************************************************
TH2D h_cov = TMatrixTSym_to_TH2D( TMatrixTSym matT, int nRow, int minRow=0 ){
//****************************************************************************
//****************************************************************************

  // note:  symmetric matrix --> nRow=nCol
  // To optimise time, could only loop over top triangle since it is symmetric
  // - not gotten round to doing that yet

  // save to the heap to avoid memory leak
  TH2D h = TH2D("h", "h", nRows, 0, nRows, nCol, 0, nCol);

  for( int irow = minRow ; irow< nRow ; irow++ ){    
    for( int jcolumn = minRow;  jcolumn< nRow; jcolumn++ ){

      // read TMatrixTSym      
      double e =(*matT)[irow + minRow][jcolumn + minCol];

      //  +1 because first histo bin is bin1  (bin0 is overlfow)
      h->SetBinContent( irow+1, jcolumn+1, e );

  return h;
}


// Read out the min and max bins of a TH2D histo

//****************************************************
void readOutMinMax_TH2D( TH2D h, int nRow, int nCol ){
//****************************************************
 //****************************************************

  int min, minRow, minCol;
  int max, maxRow, maxCol;
 
  for( int irow = 0 ; irow< nRow; irow++ ){
    for( int jcolumn = 0;  jcolumn< nCol; jcolumn++ ){

      //  +1 because first histo bin is bin1  (bin0 is overlfow)
      double e = h->GetBinContent( irow+1, jcolumn+1, e );
  
      if( irow == jcolumn == 0 )  min = max = e;

      if( e < min ) {min = e; minRow = irow; minCol =jcol; }
      if( e > max ) {max = e; maxRow = irow; maxCol =jcol; }

    }// jcolumn
  }// irow


  if( min && minRow && minCol ) std::cout<<"Min bin:  ("<< minRow <<", "<< minCol <<") = " << min << std::endl;
  if( max && maxRow && maxCol ) std::cout<<"Max bin:  ("<< maxRow <<", "<< maxCol <<") = " << max << std::endl;
  return;
}


// Return the min and max bins of a TH2D histo

//****************************************************
void readOutMinMax_TH2D( TH2D h, int nRow, int nCol ){
//****************************************************
 //****************************************************

  int min, minRow, minCol;
  int max, maxRow, maxCol;
 
  for( int irow = 0 ; irow< nRow; irow++ ){
    for( int jcolumn = 0;  jcolumn< nCol; jcolumn++ ){

      //  +1 because first histo bin is bin1  (bin0 is overlfow)
      double e = h->GetBinContent( irow+1, jcolumn+1, e );
  
      if( irow == jcolumn == 0 )  min = max = e;

      if( e < min ) {min = e; minRow = irow; minCol =jcol; }
      if( e > max ) {max = e; maxRow = irow; maxCol =jcol; }

    }// jcolumn
  }// irow


  if( min && minRow && minCol ) std::cout<<"Min bin:  ("<< minRow <<", "<< minCol <<") = " << min << std::endl;
  if( max && maxRow && maxCol ) std::cout<<"Max bin:  ("<< maxRow <<", "<< maxCol <<") = " << max << std::endl;
  return;
}
