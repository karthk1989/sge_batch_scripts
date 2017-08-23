{

   //Set up for the covariance calculation

   const int nthrows = 100;
   const int nbins = 20;
   const int ndet = 4;

//   const int nthrows = 50;
//   const int nbins = 20;
//   const int ndet = 28;


   char filePrefix[4][200] = {"../na61_outputs/nd5_fhc_NA61","../na61_outputs/nd5_rhc_NA61","../na61_outputs/1_sk_fhc_NA61", "../na61_outputs/1_sk_rhc_NA61"};
   char nomFile[4][200] = {"../nominal_outputs/nd5_fhc_NOM.root","../nominal_outputs/nd5_rhc_NOM.root","../nominal_outputs/1_sk_fhc_NOM.root","../nominal_outputs/1_sk_rhc_NOM.root"};
 
 
/*   char filePrefix[28][200] = {    "../na61_outputs/1_sk_fhc_NA61",     "../na61_outputs/1_sk_rhc_NA61",
   			      "../na61_outputs/2_hktoch_fhc_NA61", "../na61_outputs/2_hktoch_rhc_NA61",
   			       "../na61_outputs/3_hkhak_fhc_NA61",  "../na61_outputs/3_hkhak_rhc_NA61",
   			      "../na61_outputs/4_hkkbis_fhc_NA61", "../na61_outputs/4_hkkbis_rhc_NA61",
   			      "../na61_outputs/5_hkkboh_fhc_NA61", "../na61_outputs/5_hkkboh_rhc_NA61",
   			      "../na61_outputs/nd1_fhc_NA61", "../na61_outputs/nd1_rhc_NA61",
   			      "../na61_outputs/nd2_fhc_NA61", "../na61_outputs/nd2_rhc_NA61",
   			      "../na61_outputs/nd3_fhc_NA61", "../na61_outputs/nd3_rhc_NA61",
   			      "../na61_outputs/nd4_fhc_NA61", "../na61_outputs/nd4_rhc_NA61",
   			      "../na61_outputs/nd5_fhc_NA61", "../na61_outputs/nd5_rhc_NA61",
   			      "../na61_outputs/nd6_fhc_NA61", "../na61_outputs/nd6_rhc_NA61",
   			      "../na61_outputs/nd7_fhc_NA61", "../na61_outputs/nd7_rhc_NA61",
   			      "../na61_outputs/nd8_fhc_NA61", "../na61_outputs/nd8_rhc_NA61",
   			      "../na61_outputs/nd9_fhc_NA61", "../na61_outputs/nd9_rhc_NA61"   			      
   			     }; // soph
   			      
   char nomFile[28][200] = {    "../nominal_outputs/1_sk_fhc_NOM.root",    "../nominal_outputs/1_sk_rhc_NOM.root",
			   "../nominal_outputs/2_hktoch_fhc_NOM.root","../nominal_outputs/2_hktoch_rhc_NOM.root",
			    "../nominal_outputs/3_hkhak_fhc_NOM.root", "../nominal_outputs/3_hkhak_rhc_NOM.root",
			   "../nominal_outputs/4_hkkbis_fhc_NOM.root","../nominal_outputs/4_hkkbis_rhc_NOM.root",
			   "../nominal_outputs/5_hkkboh_fhc_NOM.root","../nominal_outputs/5_hkkboh_rhc_NOM.root",
			   "../nominal_outputs/nd1_fhc_NOM.root","../nominal_outputs/nd1_fhc_NOM.root",
			   "../nominal_outputs/nd2_fhc_NOM.root","../nominal_outputs/nd2_fhc_NOM.root",
			   "../nominal_outputs/nd3_fhc_NOM.root","../nominal_outputs/nd3_fhc_NOM.root",
			   "../nominal_outputs/nd4_fhc_NOM.root","../nominal_outputs/nd4_fhc_NOM.root",
			   "../nominal_outputs/nd5_fhc_NOM.root","../nominal_outputs/nd5_fhc_NOM.root",
			   "../nominal_outputs/nd6_fhc_NOM.root","../nominal_outputs/nd6_fhc_NOM.root",
			   "../nominal_outputs/nd7_fhc_NOM.root","../nominal_outputs/nd7_fhc_NOM.root",
			   "../nominal_outputs/nd8_fhc_NOM.root","../nominal_outputs/nd8_fhc_NOM.root",
			   "../nominal_outputs/nd9_fhc_NOM.root","../nominal_outputs/nd9_fhc_NOM.root", 		  
   			  };// soph
*/


   const int nflavor = 4;
   char flavors[4][50] = {"numu","numubar","nue","nuebar"};

   int nEntries = nbins*ndet*nflavor;
   
   std::cout<<"nthrows = "<< nthrows << std::endl;
   std::cout<<""<<std::endl;
   
   std::cout<<" nbins              = " << nbins << std::endl;
   std::cout<<" ndet ( rhc + fhc ) = " << ndet << std::endl;
   std::cout<<" nflavour           = " << nflavor << std::endl;
   std::cout<<"			nEntries = nbins*ndet*nflavor = " << nEntries << std::endl;

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
   std::cout<<"check we're getting numbers out!  :    (*cov)(2,2) = " <<  (*cov)(2,3)  << std::endl;
   
   TFile *fout = new TFile("na61_mult_cov.root","RECREATE");
   cov->Write("na61_mult_cov");
   fout->Close();

}     


