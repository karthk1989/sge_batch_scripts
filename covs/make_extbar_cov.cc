{

   //Set up for the covariance calculation
   const int nthrows = 1;
   const int nbins = 20;
   const int ndet = 4;
   char filePrefix[4][200] = {"../snmult_outputs/nd5_fhc_SNEXTBAR","../snmult_outputs/nd5_rhc_SNEXTBAR","../snmult_outputs/sk_fhc_SNEXTBAR", "../snmult_outputs/sk_rhc_SNEXTBAR"};
   char nomFile[4][200] = {"../nominal_outputs/nd5_fhc_NOM.root","../nominal_outputs/nd5_rhc_NOM.root","../nominal_outputs/sk_fhc_NOM.root","../nominal_outputs/sk_rhc_NOM.root"};
   const int nflavor = 4;
   char flavors[4][50] = {"numu","numubar","nue","nuebar"};

   int nEntries = nbins*ndet*nflavor;

   //Set up the arrays and covariance matrix
   double *nomvals = new double[nEntries];
   double *throws = new double[nEntries];
   TMatrixTSym<double> *cov = new TMatrixTSym<double>(nEntries);
   for(int i=0; i<nEntries; i++)
     for(int j=0; j<nEntries; j++)
       (*cov)(i,j) = 0.;

   //Save the nomvals flux values
   int iter = 0;
   for(int i=0; i<ndet; i++){
     TFile *fnom = new TFile(nomFile[i]);
     for(int j=0; j<nflavor; j++){
       TH1D *tmp = (TH1D*)fnom->Get(Form("flux_%s",flavors[j]));
       for(int k=0; k<nbins; k++){
          nomvals[iter] = tmp->GetBinContent(k+1);
          if(nomvals[iter]!=nomvals[iter]) nomvals[iter] = 0.;
          iter++;
       }
     }
   }    

   //Build the covariance matrix from the throws
   for(int n=0; n<nthrows; n++){
     int iter = 0;
     for(int i=0; i<ndet; i++){
       TFile *fthrow = new TFile(Form("%s_%d.root",filePrefix[i],n));
       for(int j=0; j<nflavor; j++){
         TH1D *tmp = (TH1D*)fthrow->Get(Form("flux_%s",flavors[j]));
         for(int k=0; k<nbins; k++){ 
            throws[iter] = tmp->GetBinContent(k+1);
            if(throws[iter]!=throws[iter]) throws[iter] = 0.;
            iter++;
         }
       }
     }
     for(int i=0; i<nEntries; i++){
       //std::cout << nomvals[i] << std::endl;
       for(int j=0; j<nEntries; j++){
         if(nomvals[i]>0. && nomvals[j]>0.){
           (*cov)(i,j) += (1.0-throws[i]/nomvals[i])*(1.0-throws[j]/nomvals[j])/(double)nthrows;
         }  
       }
     }  
   }

   TFile *fout = new TFile("sec_nucl_extbar_cov.root","RECREATE");
   cov->Write("sec_nucl_extbar_cov");
   fout->Close();

}     


