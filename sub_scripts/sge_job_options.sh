#!/bin/bash
#$ -S /bin/bash
#$ -cwd


## Sophie King  soph.e.king123@gmail.com
## Expanded version of submission scripts written by Mark Hartz

## Written for SGE batch system
## source /opt/sge/default/common/settings.sh
## qsub job.sh

## ---- Systematic submission scripts ---- ##
## For a given systematic 'X'
## sge_X_loop.sh submits multiple instances of sge_X_job.sh
## sge_X_job.sh sources sge_job_options.sh and runs sge_job_framework.sh with the corresponding variables set for syst X
## sge_job_framework.sh executes 'flux_throws' for syst X
## User instructions:  Set variables in sge_job_options.sh, set SGE setup file in sge_X_loop.sh and run sge_X_loop.sh
## --------------------------------------- ##


## This file:  sge_job_options.sh
## set varibales and options for sge_job_framework.sh  

## turn on/off FHC/RHC
## turn on/off different detectors and their FVs
## set the FV sizes
## set path to flux_tuning scripts
## set path to flux files
## set output directory
## set file to source for ROOT


  run_FHC=true;  run_RHC=true;
  
  run_1_sk=true; run_2_hktoch=true; run_3_hkhak=true; run_4_hkkbis=true; run_5_hkkboh=true;
  
  run_nd1=true: run_nd1_fv=false;	# 2km det
  run_nd2=true; run_nd2_fv=true;	# surface det
  run_nd3=true; run_nd3_fv=false;	# INGRID hori.
  run_nd4=true; run_nd4_fv=false;	# INGRID vert.
  run_nd5=true; run_nd5_fv=true;	# nd280 basket
  run_nd6=true; run_nd6_fv=true;	# nd280 magnet  
  run_nd7=true;			# IWCD toch dir
  run_nd8=true;			# IWCD moz dir
  run_nd9=true;			# IWCD X=0 dir
    run_nd9_fv_h10=true;   # diff. angles/samples of E61 in X=0 dir
    run_nd9_fv_h7p7=true;  # diff. angles/samples of E61 in X=0 dir

  fv_nd1="-xmin -9999  -xmax 9999   -ymin -9999  -ymax 999"  
  fv_nd2="-xmin -400  -xmax 400   -ymin -300  -ymax 300"
  fv_nd3="-xmin -9999  -xmax 9999   -ymin -9999  -ymax 9999"
  fv_nd4="-xmin -9999  -xmax 9999   -ymin -9999  -ymax 9999"  
  fv_nd5="-xmin -87.451  -xmax 87.451   -ymin -87.451  -ymax 87.451"
  fv_nd6="-xmin -87.451  -xmax 87.451   -ymin -87.451  -ymax 87.451"
  
  # FV is 1000cm in y direction
  # fiducial volumes overlap
  fv_nd9_fv1_h10="-xmin -400  -xmax 400   -ymin 1750   -ymax 2750"
  fv_nd9_fv2_h10="-xmin -400  -xmax 400   -ymin 1000   -ymax 2000"
  fv_nd9_fv3_h10="-xmin -400  -xmax 400   -ymin 250    -ymax 1250"
  fv_nd9_fv4_h10="-xmin -400  -xmax 400   -ymin -500   -ymax 500"
  fv_nd9_fv5_h10="-xmin -400  -xmax 400   -ymin -1250  -ymax -250"
  fv_nd9_fv6_h10="-xmin -400  -xmax 400   -ymin -2000  -ymax -1000"
  fv_nd9_fv7_h10="-xmin -400  -xmax 400   -ymin -2750  -ymax -1750"

  # FV is 770cm in y direction
  # fiducial volumes do NOT overlap
  fv_nd9_fv1_h7p7="-xmin -400  -xmax 400   -ymin 1925   -ymax 2695"
  fv_nd9_fv2_h7p7="-xmin -400  -xmax 400   -ymin 1155   -ymax 1925"
  fv_nd9_fv3_h7p7="-xmin -400  -xmax 400   -ymin 385    -ymax 1155"
  fv_nd9_fv4_h7p7="-xmin -400  -xmax 400   -ymin -385   -ymax 385"
  fv_nd9_fv5_h7p7="-xmin -400  -xmax 400   -ymin -1155  -ymax -385"
  fv_nd9_fv6_h7p7="-xmin -400  -xmax 400   -ymin -1925  -ymax -1155"
  fv_nd9_fv7_h7p7="-xmin -400  -xmax 400   -ymin -2695  -ymax -1925"


  WORKDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/flux_tuning

  NDFHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/1_sk_nd/pos
  sk_1_FHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/1_sk_nd/pos
  hktoch_2_FHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/2_hktoch/pos
  hkhak_3_FHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/3_hkhak/pos
  hkkbis_4_FHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/4_hkkbis/pos
  hkkboh_5_FHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/5_hkkboh/pos

  NDRHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/1_sk_nd/neg
  sk_1_RHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/1_sk_nd/neg
  hktoch_2_RHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/2_hktoch/neg
  hkhak_3_RHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/3_hkhak/neg
  hkkbis_4_RHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/4_hkkbis/neg
  hkkboh_5_RHCDIR=/data/hyperk/fluxes/flukaFluxSet_allConfig/5_hkkboh/neg

#  OUT=${WORKDIR}/nominal_outputs
  OUT_BASE=/data/hyperk/fluxes/flukaFluxSet_allConfig/flux_tuning/error_scripts/sge_batch_scripts_work/  

   #check if output directory exists.  If not make it
 if [[ -d ${OUT_BASE} ]]; then
   echo "Output base directory exists"
 else
   echo "Creating base output directory"
   mkdir ${OUT_BASE}
 fi

  # flux tuning independent from jnubeam - all you need is root
  # source file to setup ROOT
  source /data/king/t2k/work/nd280/v11r31p27/nd280/v11r31p27/cmt/setup_v11r31p27.sh
  # point it to the libraries
  export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:${WORKDIR}/lib
 
 # XXX -------------------------------- XXX #
 
