//
//  NOTE:  For the histograms   _NOM_.root   and   _SYST_X.root: 
//
//               bin(1)  - first energy bin
//               bin(19) - last energy bin	
//               bin(02) - overflow bin 
//
//               --> this applies too the cov too   cov(20,20) will be an overflow energy bin
//
//  XXX ENERGY BIN 20 IS OVERFLOW XXX //





{


// produces readout of full set of bin numbers
  int binLow=1;
  for( int i=1; i<31; i++ ){
    
    std::cout<< "det " << i << ":   low bin= "<< binLow <<"  high bin= " << binLow+79 << ":  "
      " numu="<< binLow <<"-"<< binLow+19 <<
      ", anumu="<< binLow +20 <<"-"<< binLow+39 <<
      ", nue="<< binLow +40 <<"-"<< binLow+59 <<
      ", anue="<< binLow +60 <<"-"<< binLow+79 << std::endl;
    
    binLow = binLow +80;
  }

  std::cout<<""<<std::endl;
  std::cout<<""<<std::endl;



// produces alternate readout of full set of bin numbers
  binLow=1;
    for( int i=1; i<31; i++ ){

      std::cout << "const int det_"<<i<<"_lowBin="<< binLow << ";  const int det_"<<i<<"_highBin=" << binLow+79 << ";  //"
      "  numu="<< binLow <<"-"<< binLow+19 <<
      ", anumu="<< binLow +20 <<"-"<< binLow+39 <<
      ", nue="<< binLow +40 <<"-"<< binLow+59 <<
      ", anue="<< binLow +60 <<"-"<< binLow+79 << std::endl;

    binLow = binLow +80;
  }


