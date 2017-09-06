{

  int binLow=1;
  for( int i=1; i<31; i++ ){
    
    std::cout<< "det " << i << ":   low bin= "<< binLow <<"  high bin= " << binLow+79 << ":  "
      " numu="<< binLow <<"-"<< binLow+19 <<
      ", anumu="<< binLow +20 <<"-"<< binLow+39 <<
      ", nue="<< binLow +40 <<"-"<< binLow+59 <<
      ", anue="<< binLow +60 <<"-"<< binLow+79 << std::endl;
    
    binLow = binLow +80;
  }
}
