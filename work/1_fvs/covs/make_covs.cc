//  1_sk_fhc  1_sk_rhc
//  2_hktoch_fhc  2_hktoch_rhc
//
//
//	
//


{

  bool alttert		= true;
  bool bmpt 		= false;
  bool harp 		= false;
  bool na61 		= false;		int na61Throws = 100;
  bool oaax 		= false;
  bool oaay 		= false;
  bool pbeamx 		= false;
  bool pbeamy		= false;
  bool prodx 		= false;		int prodxThrows = 100;
  bool snextbar		= false;
  bool snleadbar	= false;
  bool snmult		= false;		int snmultThrows = 100;

  std::string save_prefix = "1_fvs__sk_nd5_nd2_nd9h7p7_hk2_hk3_hkk4_hhk5_";


  if(alttert){
    std::string str_cov_name =  "alttert_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "ALTTERT";  std::string systDir = "../out/alttert_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = 1;
  }
  if(bmpt){
    std::string str_cov_name =  "bmpt_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "BMPT";  std::string systDir = "../out/bmpt_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = 1;
  }
  if(harp){
    std::string str_cov_name =  "harp_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "HARP";  std::string systDir = "../out/harp_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = 1;
  }
  if(na61){
    std::string str_cov_name =  "na61_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "NA61";  std::string systDir = "../out/na61_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = na61Throws;
  }
  if(oaax){
    std::string str_cov_name =  "oaax_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "OAAX";  std::string systDir = "../out/oaax_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = 2;
  }
  if(oaay){
    std::string str_cov_name =  "oaay_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "OAAY";  std::string systDir = "../out/oaay_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = 2;
  }
  if(pbeamx){
    std::string str_cov_name =  "pbeamx_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "PBEAMX";  std::string systDir = "../out/pbeamx_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = 50;
  }
  if(pbeamy){
    std::string str_cov_name =  "pbeamy_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "PBEAMY";  std::string systDir = "../out/pbeamy_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = 50;
  }
  if(prodx){
    std::string str_cov_name =  "prodx_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "PRODX";  std::string systDir = "../out/prodx_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";

    const int nthrows = prodxThrows;
  }
  else if(snextbar){
    std::string str_cov_name =  "snextbar_cov";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "SNEXTBAR";  std::string systDir = "../out/snextbar_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";
    
    const int nthrows = 1;
  }
  else if(snleadbar){
    std::string str_cov_name =  "snleadbar";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "SNLEADBAR";  std::string systDir = "../out/snleadbar_outputs/";
    std::string nomDir = "../out/nominal_outputs/";
    std::string nom = "_NOM_.root";
    
    const int nthrows = 2;
  }
  else if(snmult){
    std::string str_cov_name =  "snmult";  const char* cov_name = str_cov_name.c_str();
    std::string str_save1 = save_prefix + str_cov_name + ".root";  
    const char* save1 = str_save1.c_str();

    std::string NAME = "SNMULT";  std::string systDir = "../out/snmult_outputs/";
    std::string nomDir = "../out/snmult_outputs/";
    std::string nom = "_SNMULT_-1.root";
    
    const int nthrows = snmultThrows;
  }
  
  int dets = 0;

  bool b_sk_1 = true;		if( b_sk_1 ) dets++;   
  bool b_nd5_fv = true;		if( b_nd5_fv ) dets++;

  bool b_nd2_fv = true;		if( b_nd2_fv ) dets++;

  bool b_nd9_fv1_h10 = false;	if( b_nd9_fv1_h10 ) dets++;
  bool b_nd9_fv2_h10 = false;	if( b_nd9_fv2_h10 ) dets++;
  bool b_nd9_fv3_h10 = false;	if( b_nd9_fv3_h10 ) dets++;
  bool b_nd9_fv4_h10 = false;	if( b_nd9_fv4_h10 ) dets++;
  bool b_nd9_fv5_h10 = false;	if( b_nd9_fv5_h10 ) dets++;
  bool b_nd9_fv6_h10 = false;	if( b_nd9_fv6_h10 ) dets++;
  bool b_nd9_fv7_h10 = false;	if( b_nd9_fv7_h10 ) dets++; 

  bool b_nd9_fv1_h7p7 = true;	if( b_nd9_fv1_h7p7 ) dets++;
  bool b_nd9_fv2_h7p7 = true;	if( b_nd9_fv2_h7p7 ) dets++;
  bool b_nd9_fv3_h7p7 = true;	if( b_nd9_fv3_h7p7 ) dets++;
  bool b_nd9_fv4_h7p7 = true;	if( b_nd9_fv4_h7p7 ) dets++;
  bool b_nd9_fv5_h7p7 = true;	if( b_nd9_fv5_h7p7 ) dets++;
  bool b_nd9_fv6_h7p7 = true;	if( b_nd9_fv6_h7p7 ) dets++;
  bool b_nd9_fv7_h7p7 = true;	if( b_nd9_fv7_h7p7 ) dets++; 

  bool b_hktoch_2 = true;	if( b_hktoch_2 ) dets++;
  bool b_hkhak_3 = true;	if( b_hkhak_3 ) dets++;
  bool b_hkkbis_4 = true;	if( b_hkkbis_4 ) dets++;
  bool b_hkkboh_5 = true;	if( b_hkkboh_5 ) dets++;

  bool b_fhc = true;  bool b_rhc = true;  if(b_fhc && b_rhc) dets=dets*2;
  

  const int nbins = 20;
  const int ndet = dets;
  std::cout<<" ndet = " << dets << std::endl;


 		//// fhc ////								//// rhc ////
 std::string  sk_1_fhc= systDir+"1_sk_fhc_" + NAME;			std::string  sk_1_rhc= systDir+"1_sk_rhc_" + NAME;  		
 std::string  nd5_fhc_fv= systDir+"nd5_fhc_fv_" + NAME;			std::string  nd5_rhc_fv= systDir+"nd5_rhc_fv_" + NAME;		
 std::string  nd2_fhc_fv= systDir+"nd2_fhc_fv_" + NAME;			std::string  nd2_rhc_fv= systDir+"nd2_rhc_fv_" + NAME; 		
 std::string  nd9_fhc_fv1_h10= systDir+"nd9_fhc_fv1_h10_" + NAME;	std::string  nd9_rhc_fv1_h10= systDir+"nd9_rhc_fv1_h10_" + NAME;
 std::string  nd9_fhc_fv2_h10= systDir+"nd9_fhc_fv2_h10_" + NAME;	std::string  nd9_rhc_fv2_h10= systDir+"nd9_rhc_fv2_h10_" + NAME;
 std::string  nd9_fhc_fv3_h10= systDir+"nd9_fhc_fv3_h10_" + NAME;	std::string  nd9_rhc_fv3_h10= systDir+"nd9_rhc_fv3_h10_" + NAME;
 std::string  nd9_fhc_fv4_h10= systDir+"nd9_fhc_fv4_h10_" + NAME;	std::string  nd9_rhc_fv4_h10= systDir+"nd9_rhc_fv4_h10_" + NAME;
 std::string  nd9_fhc_fv5_h10= systDir+"nd9_fhc_fv5_h10_" + NAME;	std::string  nd9_rhc_fv5_h10= systDir+"nd9_rhc_fv5_h10_" + NAME;
 std::string  nd9_fhc_fv6_h10= systDir+"nd9_fhc_fv6_h10_" + NAME;	std::string  nd9_rhc_fv6_h10= systDir+"nd9_rhc_fv6_h10_" + NAME;
 std::string  nd9_fhc_fv7_h10= systDir+"nd9_fhc_fv7_h10_" + NAME;	std::string  nd9_rhc_fv7_h10= systDir+"nd9_rhc_fv7_h10_" + NAME;
 std::string  nd9_fhc_fv1_h7p7= systDir+"nd9_fhc_fv1_h7p7_" + NAME;	std::string  nd9_rhc_fv1_h7p7= systDir+"nd9_rhc_fv1_h7p7_" + NAME;
 std::string  nd9_fhc_fv2_h7p7= systDir+"nd9_fhc_fv2_h7p7_" + NAME;	std::string  nd9_rhc_fv2_h7p7= systDir+"nd9_rhc_fv2_h7p7_" + NAME;
 std::string  nd9_fhc_fv3_h7p7= systDir+"nd9_fhc_fv3_h7p7_" + NAME;	std::string  nd9_rhc_fv3_h7p7= systDir+"nd9_rhc_fv3_h7p7_" + NAME;
 std::string  nd9_fhc_fv4_h7p7= systDir+"nd9_fhc_fv4_h7p7_" + NAME;	std::string  nd9_rhc_fv4_h7p7= systDir+"nd9_rhc_fv4_h7p7_" + NAME;
 std::string  nd9_fhc_fv5_h7p7= systDir+"nd9_fhc_fv5_h7p7_" + NAME;	std::string  nd9_rhc_fv5_h7p7= systDir+"nd9_rhc_fv5_h7p7_" + NAME;
 std::string  nd9_fhc_fv6_h7p7= systDir+"nd9_fhc_fv6_h7p7_" + NAME;	std::string  nd9_rhc_fv6_h7p7= systDir+"nd9_rhc_fv6_h7p7_" + NAME;
 std::string  nd9_fhc_fv7_h7p7= systDir+"nd9_fhc_fv7_h7p7_" + NAME;	std::string  nd9_rhc_fv7_h7p7= systDir+"nd9_rhc_fv7_h7p7_" + NAME;
 std::string  hktoch_2_fhc= systDir+"2_hktoch_fhc_" + NAME;		std::string  hktoch_2_rhc= systDir+"2_hktoch_rhc_" + NAME;	
 std::string  hkhak_3_fhc= systDir+"3_hkhak_fhc_" + NAME;		std::string  hkhak_3_rhc= systDir+"3_hkhak_rhc_" + NAME;	
 std::string  hkkbis_4_fhc= systDir+"4_hkkbis_fhc_" + NAME;		std::string  hkkbis_4_rhc= systDir+"4_hkkbis_rhc_" + NAME;	
 std::string  hkkboh_5_fhc= systDir+"5_hkkboh_fhc_" + NAME;		std::string  hkkboh_5_rhc= systDir+"5_hkkboh_rhc_" + NAME;	

 
 std::string  N_sk_1_fhc= nomDir+"1_sk_fhc"+nom;			std::string  N_sk_1_rhc= nomDir+"1_sk_rhc"+nom;				
 std::string  N_nd5_fhc_fv= nomDir+"nd5_fhc_fv"+nom;			std::string  N_nd5_rhc_fv= nomDir+"nd5_rhc_fv"+nom;			
 std::string  N_nd2_fhc_fv= nomDir+"nd2_fhc_fv"+nom;			std::string  N_nd2_rhc_fv= nomDir+"nd2_rhc_fv"+nom; 		
 std::string  N_nd9_fhc_fv1_h10= nomDir+"nd9_fhc_fv1_h10"+nom;		std::string  N_nd9_rhc_fv1_h10= nomDir+"nd9_rhc_fv1_h10"+nom;	
 std::string  N_nd9_fhc_fv2_h10= nomDir+"nd9_fhc_fv2_h10"+nom;		std::string  N_nd9_rhc_fv2_h10= nomDir+"nd9_rhc_fv2_h10"+nom;	
 std::string  N_nd9_fhc_fv3_h10= nomDir+"nd9_fhc_fv3_h10"+nom;		std::string  N_nd9_rhc_fv3_h10= nomDir+"nd9_rhc_fv3_h10"+nom;	
 std::string  N_nd9_fhc_fv4_h10= nomDir+"nd9_fhc_fv4_h10"+nom;		std::string  N_nd9_rhc_fv4_h10= nomDir+"nd9_rhc_fv4_h10"+nom;	
 std::string  N_nd9_fhc_fv5_h10= nomDir+"nd9_fhc_fv5_h10"+nom;		std::string  N_nd9_rhc_fv5_h10= nomDir+"nd9_rhc_fv5_h10"+nom;	
 std::string  N_nd9_fhc_fv6_h10= nomDir+"nd9_fhc_fv6_h10"+nom;		std::string  N_nd9_rhc_fv6_h10= nomDir+"nd9_rhc_fv6_h10"+nom;	
 std::string  N_nd9_fhc_fv7_h10= nomDir+"nd9_fhc_fv7_h10"+nom;		std::string  N_nd9_rhc_fv7_h10= nomDir+"nd9_rhc_fv7_h10"+nom;	
 std::string  N_nd9_fhc_fv1_h7p7= nomDir+"nd9_fhc_fv1_h7p7"+nom;	std::string  N_nd9_rhc_fv1_h7p7= nomDir+"nd9_rhc_fv1_h7p7"+nom;	
 std::string  N_nd9_fhc_fv2_h7p7= nomDir+"nd9_fhc_fv2_h7p7"+nom;	std::string  N_nd9_rhc_fv2_h7p7= nomDir+"nd9_rhc_fv2_h7p7"+nom;	
 std::string  N_nd9_fhc_fv3_h7p7= nomDir+"nd9_fhc_fv3_h7p7"+nom;	std::string  N_nd9_rhc_fv3_h7p7= nomDir+"nd9_rhc_fv3_h7p7"+nom;	
 std::string  N_nd9_fhc_fv4_h7p7= nomDir+"nd9_fhc_fv4_h7p7"+nom;	std::string  N_nd9_rhc_fv4_h7p7= nomDir+"nd9_rhc_fv4_h7p7"+nom;	
 std::string  N_nd9_fhc_fv5_h7p7= nomDir+"nd9_fhc_fv5_h7p7"+nom;	std::string  N_nd9_rhc_fv5_h7p7= nomDir+"nd9_rhc_fv5_h7p7"+nom;	
 std::string  N_nd9_fhc_fv6_h7p7= nomDir+"nd9_fhc_fv6_h7p7"+nom;	std::string  N_nd9_rhc_fv6_h7p7= nomDir+"nd9_rhc_fv6_h7p7"+nom;	
 std::string  N_nd9_fhc_fv7_h7p7= nomDir+"nd9_fhc_fv7_h7p7"+nom;	std::string  N_nd9_rhc_fv7_h7p7= nomDir+"nd9_rhc_fv7_h7p7"+nom;	
 std::string  N_hktoch_2_fhc= nomDir+"2_hktoch_fhc"+nom;		std::string  N_hktoch_2_rhc= nomDir+"2_hktoch_rhc"+nom;		
 std::string  N_hkhak_3_fhc= nomDir+"3_hkhak_fhc"+nom;			std::string  N_hkhak_3_rhc= nomDir+"3_hkhak_rhc"+nom;		
 std::string  N_hkkbis_4_fhc= nomDir+"4_hkkbis_fhc"+nom;		std::string  N_hkkbis_4_rhc= nomDir+"4_hkkbis_rhc"+nom;		
 std::string  N_hkkboh_5_fhc= nomDir+"5_hkkboh_fhc"+nom;		std::string  N_hkkboh_5_rhc= nomDir+"5_hkkboh_rhc"+nom;		


   
   char filePrefix[ ndet ][200];   
   char nomFile[ ndet ][200]   ;   
   
   int it = 0; 
   if( b_sk_1 && b_fhc ) 	{ strcpy( filePrefix[it], sk_1_fhc.c_str() ) ;  	strcpy( nomFile[it], N_sk_1_fhc.c_str() ) ;  it++ ; 		}
   if( b_sk_1 && b_rhc )	{ strcpy( filePrefix[it], sk_1_rhc.c_str() ) ;  	strcpy( nomFile[it], N_sk_1_rhc.c_str() ) ;  it++ ; 		}
   if( b_nd5_fv && b_fhc )	{ strcpy( filePrefix[it], nd5_fhc_fv.c_str() ) ;  	strcpy( nomFile[it], N_nd5_fhc_fv.c_str() ) ;  it++ ;		}
   if( b_nd5_fv && b_rhc )	{ strcpy( filePrefix[it], nd5_rhc_fv.c_str() ) ;       	strcpy( nomFile[it], N_nd5_rhc_fv.c_str() ) ;  it++ ;		}	
   if( b_nd2_fv && b_fhc )	{ strcpy( filePrefix[it], nd2_fhc_fv.c_str() ) ;  	strcpy( nomFile[it], N_nd2_fhc_fv.c_str() ) ;  it++ ;		}	
   if( b_nd2_fv && b_rhc )	{ strcpy( filePrefix[it], nd2_rhc_fv.c_str() ) ;       	strcpy( nomFile[it], N_nd2_rhc_fv.c_str() ) ;  it++ ;		}
   if( b_nd9_fv1_h10 && b_fhc )	{ strcpy( filePrefix[it], nd9_fhc_fv1_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_fhc_fv1_h10.c_str() ) ;  it++ ;	}	
   if( b_nd9_fv1_h10 && b_rhc )	{ strcpy( filePrefix[it], nd9_rhc_fv1_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_rhc_fv1_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv2_h10 && b_fhc )	{ strcpy( filePrefix[it], nd9_fhc_fv2_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_fhc_fv2_h10.c_str() ) ;  it++ ;	}	
   if( b_nd9_fv2_h10 && b_rhc )	{ strcpy( filePrefix[it], nd9_rhc_fv2_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_rhc_fv2_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv3_h10 && b_fhc )	{ strcpy( filePrefix[it], nd9_fhc_fv3_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_fhc_fv3_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv3_h10 && b_rhc )	{ strcpy( filePrefix[it], nd9_rhc_fv3_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_rhc_fv3_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv4_h10 && b_fhc )	{ strcpy( filePrefix[it], nd9_fhc_fv4_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_fhc_fv4_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv4_h10 && b_rhc )	{ strcpy( filePrefix[it], nd9_rhc_fv4_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_rhc_fv4_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv5_h10 && b_fhc )	{ strcpy( filePrefix[it], nd9_fhc_fv5_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_fhc_fv5_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv5_h10 && b_rhc )	{ strcpy( filePrefix[it], nd9_rhc_fv5_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_rhc_fv5_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv6_h10 && b_fhc )	{ strcpy( filePrefix[it], nd9_fhc_fv6_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_fhc_fv6_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv6_h10 && b_rhc )	{ strcpy( filePrefix[it], nd9_rhc_fv6_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_rhc_fv6_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv7_h10 && b_fhc )	{ strcpy( filePrefix[it], nd9_fhc_fv7_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_fhc_fv7_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv7_h10 && b_rhc )	{ strcpy( filePrefix[it], nd9_rhc_fv7_h10.c_str() ) ;  	strcpy( nomFile[it], N_nd9_rhc_fv7_h10.c_str() ) ;  it++ ;	}
   if( b_nd9_fv1_h7p7 && b_fhc) { strcpy( filePrefix[it], nd9_fhc_fv1_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_fhc_fv1_h7p7.c_str() ) ;  it++ ;	}	
   if( b_nd9_fv1_h7p7 && b_rhc) { strcpy( filePrefix[it], nd9_rhc_fv1_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_rhc_fv1_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv2_h7p7 && b_fhc) { strcpy( filePrefix[it], nd9_fhc_fv2_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_fhc_fv2_h7p7.c_str() ) ;  it++ ;	}	
   if( b_nd9_fv2_h7p7 && b_rhc) { strcpy( filePrefix[it], nd9_rhc_fv2_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_rhc_fv2_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv3_h7p7 && b_fhc) { strcpy( filePrefix[it], nd9_fhc_fv3_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_fhc_fv3_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv3_h7p7 && b_rhc) { strcpy( filePrefix[it], nd9_rhc_fv3_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_rhc_fv3_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv4_h7p7 && b_fhc) { strcpy( filePrefix[it], nd9_fhc_fv4_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_fhc_fv4_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv4_h7p7 && b_rhc) { strcpy( filePrefix[it], nd9_rhc_fv4_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_rhc_fv4_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv5_h7p7 && b_fhc) { strcpy( filePrefix[it], nd9_fhc_fv5_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_fhc_fv5_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv5_h7p7 && b_rhc) { strcpy( filePrefix[it], nd9_rhc_fv5_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_rhc_fv5_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv6_h7p7 && b_fhc) { strcpy( filePrefix[it], nd9_fhc_fv6_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_fhc_fv6_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv6_h7p7 && b_rhc) { strcpy( filePrefix[it], nd9_rhc_fv6_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_rhc_fv6_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv7_h7p7 && b_fhc) { strcpy( filePrefix[it], nd9_fhc_fv7_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_fhc_fv7_h7p7.c_str() ) ;  it++ ;	}
   if( b_nd9_fv7_h7p7 && b_rhc) { strcpy( filePrefix[it], nd9_rhc_fv7_h7p7.c_str() ) ; 	strcpy( nomFile[it], N_nd9_rhc_fv7_h7p7.c_str() ) ;  it++ ;	}
 
   if( b_hktoch_2 && b_fhc )	{ strcpy( filePrefix[it], hktoch_2_fhc.c_str() ) ;  	strcpy( nomFile[it], N_hktoch_2_fhc.c_str() ) ;  it++ ; 	}
   if( b_hktoch_2 && b_rhc )	{ strcpy( filePrefix[it], hktoch_2_rhc.c_str() ) ;     	strcpy( nomFile[it], N_hktoch_2_rhc.c_str() ) ;  it++ ;		}
   if( b_hkhak_3 && b_fhc )	{ strcpy( filePrefix[it], hkhak_3_fhc.c_str() ) ;  	strcpy( nomFile[it], N_hkhak_3_fhc.c_str() ) ;  it++ ; 		}
   if( b_hkhak_3 && b_rhc )	{ strcpy( filePrefix[it], hkhak_3_rhc.c_str() ) ;      	strcpy( nomFile[it], N_hkhak_3_rhc.c_str() ) ;  it++ ;		}
   if( b_hkkbis_4 && b_fhc )	{ strcpy( filePrefix[it], hkkbis_4_fhc.c_str() ) ;  	strcpy( nomFile[it], N_hkkbis_4_fhc.c_str() ) ;  it++ ;		}
   if( b_hkkbis_4 && b_rhc )	{ strcpy( filePrefix[it], hkkbis_4_rhc.c_str() ) ;     	strcpy( nomFile[it], N_hkkbis_4_rhc.c_str() ) ;  it++ ;		}
   if( b_hkkboh_5 && b_fhc )	{ strcpy( filePrefix[it], hkkboh_5_fhc.c_str() ) ;  	strcpy( nomFile[it], N_hkkboh_5_fhc.c_str() ) ;  it++ ;		}
   if( b_hkkboh_5 && b_rhc )	{ strcpy( filePrefix[it], hkkboh_5_rhc.c_str() ) ;     	strcpy( nomFile[it], N_hkkboh_5_rhc.c_str() ) ;  it++ ;		}
  

        
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
   std::cout<<" --- Saving nominal flux values --- " << std::endl;
   int iter = 0;
   TFile *fnom;
   TH1D *tmp1;
   for(int i=0; i<ndet; i++){
     fnom = new TFile(nomFile[i]);  
     for(int j=0; j<nflavor; j++){
       tmp1 = (TH1D*)fnom->Get(Form("flux_%s",flavors[j]));
       for(int k=0; k<nbins; k++){
          nomvals[iter] = tmp1->GetBinContent(k+1);
          if(nomvals[iter]!=nomvals[iter]) nomvals[iter] = 0.;
          iter++;
       }  
     }  
     fnom->Close(); 
   }  
   delete fnom; 


   //Build the covariance matrix from the throws
   std::cout<<" --- Building the covariance matrix from the throws --- " << std::endl;
   
   TFile *fthrow;
   TH1D *tmp2;
   for(int n=0; n<nthrows; n++){
     std::cout<<" Throw " << n << std::endl;
     int iter = 0;
     for(int i=0; i<ndet; i++){
       fthrow = new TFile(Form("%s_%d.root",filePrefix[i],n));
       for(int j=0; j<nflavor; j++){
         tmp2 = (TH1D*)fthrow->Get(Form("flux_%s",flavors[j]));
         for(int k=0; k<nbins; k++){ 
            throws[iter] = tmp2->GetBinContent(k+1);
            if(throws[iter]!=throws[iter]) throws[iter] = 0.;
            iter++;
         }
       }  
       fthrow->Close(); 
     }  
     delete fthrow;
     
     for(int i=0; i<nEntries; i++){
       //std::cout << nomvals[i] << std::endl;
       for(int j=0; j<nEntries; j++){
         if(nomvals[i]>0. && nomvals[j]>0.){
           (*cov)(i,j) += (1.0-throws[i]/nomvals[i])*(1.0-throws[j]/nomvals[j])/(double)nthrows;
         }  
       }
     }  
   }
   
  std::cout<<" --- Saving cov --- " <<  cov_name << " --- " <<std::endl;
  TFile *fout = new TFile( save1 ,"RECREATE");
  cov->Write( cov_name );
  fout->Close();

}     


