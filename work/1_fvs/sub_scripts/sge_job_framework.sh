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


## This file:  sge_job_framework.sh
## executes 'flux_throws' according to variables set in sge_job_options.sh and sge_X_job.sh

 

# XXX --- NOTE: must edit the options file --- XXX #
# XXX ---------- sge_job_options.sh ---------- XXX #

   echo sourcing options from ./sge_job_options.sh
   source ./sge_job_options.sh

 # XXX -------------------------------- XXX # 


echo 'Running sge_job_framework.sh '
echo NAME = ${NAME}
echo ARG = ${ARG}
echo THROW = ${THROW}
echo ' '

 EXE=${WORKDIR}/bin/flux_throws
 
 OUT=$OUT_BASE/${FOLDER}
 
 cd $WORKDIR 
 
 #check if output directory exists.  If not make it
 if [[ -d ${OUT} ]]; then
   echo "Output directory exists"
 else
   echo "Creating output directory"
   mkdir ${OUT}
 fi
 


## FHC ##
if [ "$run_FHC" = "true" ]; then

  echo executing FHC systs

  if [ "$run_1_sk" = "true" ]; then ## 1 SK
    ${EXE} -dir $sk_1_FHCDIR      -id 0  ${ARG} -o ${OUT}/1_sk_fhc_${NAME}_${THROW}.root >& ${OUT}/1_sk_fhc_${NAME}_${THROW}.log
  fi
  if [ "$run_2_hktoch" = "true" ]; then ## 2 HK -toch
    ${EXE} -dir $hktoch_2_FHCDIR  -id 0  ${ARG} -o ${OUT}/2_hktoch_fhc_${NAME}_${THROW}.root >& ${OUT}/2_hktoch_fhc_${NAME}_${THROW}.log
  fi
  if [ "$run_3_hkhak" = "true" ]; then ## 3 HK -hak
    ${EXE} -dir $hkhak_3_FHCDIR   -id 0  ${ARG} -o ${OUT}/3_hkhak_fhc_${NAME}_${THROW}.root >& ${OUT}/3_hkhak_fhc_${NAME}_${THROW}.log
  fi  
  if [ "$run_4_hkkbis" = "true" ]; then ## 4 HK -bis
    ${EXE} -dir $hkkbis_4_FHCDIR  -id 0  ${ARG} -o ${OUT}/4_hkkbis_fhc_${NAME}_${THROW}.root >& ${OUT}/4_hkkbis_fhc_${NAME}_${THROW}.log
  fi
  if [ "$run_5_hkkboh" = "true" ]; then ## 5 HK -bo
    ${EXE} -dir $hkkboh_5_FHCDIR  -id 0  ${ARG} -o ${OUT}/5_hkkboh_fhc_${NAME}_${THROW}.root >& ${OUT}/5_hkkboh_fhc_${NAME}_${THROW}.log
  fi
 #### ## 2km det
  if [ "$run_nd1" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 1  ${ARG}            -o ${OUT}/nd1_fhc_${NAME}_${THROW}.root >& ${OUT}/nd1_fhc_${NAME}_${THROW}.log     			    
  fi 
  if [ "$run_nd1_fv" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 1  ${ARG}  ${fv_nd1} -o ${OUT}/nd1_fhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd1_fhc_fv_${NAME}_${THROW}.log
  fi
 #### ## Surface det
  if [ "$run_nd2" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 2  ${ARG}            -o ${OUT}/nd2_fhc_${NAME}_${THROW}.root >& ${OUT}/nd2_fhc_${NAME}_${THROW}.log 
  fi
  if [ "$run_nd2_fv" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 2  ${ARG}  ${fv_nd2} -o ${OUT}/nd2_fhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd2_fhc_fv_${NAME}_${THROW}.log 
  fi 
 #### ## INGRID hori
  if [ "$run_nd3" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 3	 ${ARG}            -o ${OUT}/nd3_fhc_${NAME}_${THROW}.root >& ${OUT}/nd3_fhc_${NAME}_${THROW}.log  
  fi
  if [ "$run_nd3_fv" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 3  ${ARG}  ${fv_nd3} -o ${OUT}/nd3_fhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd3_fhc_fv_${NAME}_${THROW}.log  
  fi
 #### ## INGRID vert
  if [ "$run_nd4" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 4  ${ARG}            -o ${OUT}/nd4_fhc_${NAME}_${THROW}.root >& ${OUT}/nd4_fhc_${NAME}_${THROW}.log
  fi
  if [ "$run_nd4_fv" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 4  ${ARG}  ${fv_nd4} -o ${OUT}/nd4_fhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd4_fhc_fv_${NAME}_${THROW}.log
  fi
  #### ## ND280 basket  
  if [ "$run_nd5" = "true" ]; then 
    ${EXE} -dir $NDFHCDIR -id 5  ${ARG}            -o ${OUT}/nd5_fhc_${NAME}_${THROW}.root >& ${OUT}/nd5_fhc_${NAME}_${THROW}.log
  fi
  if [ "$run_nd5_fv" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 5  ${ARG}  ${fv_nd5} -o ${OUT}/nd5_fhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd5_fhc_fv_${NAME}_${THROW}.log
  fi
 #### ## ND280 magnet
  if [ "$run_nd6" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 6  ${ARG}            -o ${OUT}/nd6_fhc_${NAME}_${THROW}.root >& ${OUT}/nd6_fhc_${NAME}_${THROW}.log
  fi
  if [ "$run_nd6_fv" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 6  ${ARG}  ${fv_nd6} -o ${OUT}/nd6_fhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd6_fhc_fv_${NAME}_${THROW}.log
  fi
 #### ## WC det Toch
  if [ "$run_nd7" = "true" ]; then 
    ${EXE} -dir $NDFHCDIR -id 7  ${ARG}            -o ${OUT}/nd7_fhc_${NAME}_${THROW}.root >& ${OUT}/nd7_fhc_${NAME}_${THROW}.log
  fi
 #### ## WC det Moz
  if [ "$run_nd8" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 8  ${ARG}            -o ${OUT}/nd8_fhc_${NAME}_${THROW}.root >& ${OUT}/nd8_fhc_${NAME}_${THROW}.log 
  fi

 #### ## x=0 dir
  if [ "$run_nd9" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}            -o ${OUT}/nd9_fhc_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_${NAME}_${THROW}.log
  fi
 #### FVs of height 10m  (overlapping)
  if [ "$run_nd9_fv_h10" = "true" ]; then
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv1_h10} -o ${OUT}/nd9_fhc_fv1_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv1_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv2_h10} -o ${OUT}/nd9_fhc_fv2_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv2_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv3_h10} -o ${OUT}/nd9_fhc_fv3_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv3_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv4_h10} -o ${OUT}/nd9_fhc_fv4_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv4_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv5_h10} -o ${OUT}/nd9_fhc_fv5_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv5_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv6_h10} -o ${OUT}/nd9_fhc_fv6_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv6_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv7_h10} -o ${OUT}/nd9_fhc_fv7_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv7_h10_${NAME}_${THROW}.log     
  fi
 #### FVs of height 7.7m  (not overlapping)
  if [ "$run_nd9_fv_h7p7" = "true" ]; then 
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv1_h7p7} -o ${OUT}/nd9_fhc_fv1_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv1_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv2_h7p7} -o ${OUT}/nd9_fhc_fv2_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv2_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv3_h7p7} -o ${OUT}/nd9_fhc_fv3_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv3_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv4_h7p7} -o ${OUT}/nd9_fhc_fv4_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv4_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv5_h7p7} -o ${OUT}/nd9_fhc_fv5_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv5_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv6_h7p7} -o ${OUT}/nd9_fhc_fv6_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv6_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDFHCDIR -id 9  ${ARG}  ${fv_nd9_fv7_h7p7} -o ${OUT}/nd9_fhc_fv7_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_fhc_fv7_h7p7_${NAME}_${THROW}.log     
  fi 

fi 
 





## RHC ##
if [ "$run_RHC" = "true" ]; then

  echo executing RHC systs

  if [ "$run_1_sk" = "true" ]; then ## 1 SK
    ${EXE} -dir $sk_1_RHCDIR      -id 0  ${ARG} -o ${OUT}/1_sk_rhc_${NAME}_${THROW}.root >& ${OUT}/1_sk_rhc_${NAME}_${THROW}.log
  fi
  if [ "$run_2_hktoch" = "true" ]; then ## 2 HK -toch
    ${EXE} -dir $hktoch_2_RHCDIR  -id 0  ${ARG} -o ${OUT}/2_hktoch_rhc_${NAME}_${THROW}.root >& ${OUT}/2_hktoch_rhc_${NAME}_${THROW}.log
  fi
  if [ "$run_3_hkhak" = "true" ]; then ## 3 HK -hak
    ${EXE} -dir $hkhak_3_RHCDIR   -id 0  ${ARG} -o ${OUT}/3_hkhak_rhc_${NAME}_${THROW}.root >& ${OUT}/3_hkhak_rhc_${NAME}_${THROW}.log
  fi  
  if [ "$run_4_hkkbis" = "true" ]; then ## 4 HK -bis
    ${EXE} -dir $hkkbis_4_RHCDIR  -id 0  ${ARG} -o ${OUT}/4_hkkbis_rhc_${NAME}_${THROW}.root >& ${OUT}/4_hkkbis_rhc_${NAME}_${THROW}.log
  fi
  if [ "$run_5_hkkboh" = "true" ]; then ## 5 HK -bo
    ${EXE} -dir $hkkboh_5_RHCDIR  -id 0  ${ARG} -o ${OUT}/5_hkkboh_rhc_${NAME}_${THROW}.root >& ${OUT}/5_hkkboh_rhc_${NAME}_${THROW}.log
  fi
 #### ## 2km det
  if [ "$run_nd1" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 1  ${ARG}            -o ${OUT}/nd1_rhc_${NAME}_${THROW}.root >& ${OUT}/nd1_rhc_${NAME}_${THROW}.log     			    
  fi 
  if [ "$run_nd1_fv" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 1  ${ARG}  ${fv_nd1} -o ${OUT}/nd1_rhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd1_rhc_fv_${NAME}_${THROW}.log
  fi
 #### ## Surface det
  if [ "$run_nd2" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 2  ${ARG}            -o ${OUT}/nd2_rhc_${NAME}_${THROW}.root >& ${OUT}/nd2_rhc_${NAME}_${THROW}.log 
  fi
  if [ "$run_nd2_fv" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 2  ${ARG}  ${fv_nd2} -o ${OUT}/nd2_rhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd2_rhc_fv_${NAME}_${THROW}.log 
  fi 
 #### ## INGRID hori
  if [ "$run_nd3" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 3	 ${ARG}            -o ${OUT}/nd3_rhc_${NAME}_${THROW}.root >& ${OUT}/nd3_rhc_${NAME}_${THROW}.log  
  fi
  if [ "$run_nd3_fv" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 3  ${ARG}  ${fv_nd3} -o ${OUT}/nd3_rhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd3_rhc_fv_${NAME}_${THROW}.log  
  fi
 #### ## INGRID vert
  if [ "$run_nd4" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 4  ${ARG}            -o ${OUT}/nd4_rhc_${NAME}_${THROW}.root >& ${OUT}/nd4_rhc_${NAME}_${THROW}.log
  fi
  if [ "$run_nd4_fv" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 4  ${ARG}  ${fv_nd4} -o ${OUT}/nd4_rhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd4_rhc_fv_${NAME}_${THROW}.log
  fi
  #### ## ND280 basket  
  if [ "$run_nd5" = "true" ]; then 
    ${EXE} -dir $NDRHCDIR -id 5  ${ARG}            -o ${OUT}/nd5_rhc_${NAME}_${THROW}.root >& ${OUT}/nd5_rhc_${NAME}_${THROW}.log
  fi
  if [ "$run_nd5_fv" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 5  ${ARG}  ${fv_nd5} -o ${OUT}/nd5_rhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd5_rhc_fv_${NAME}_${THROW}.log
  fi
 #### ## ND280 magnet
  if [ "$run_nd6" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 6  ${ARG}            -o ${OUT}/nd6_rhc_${NAME}_${THROW}.root >& ${OUT}/nd6_rhc_${NAME}_${THROW}.log
  fi
  if [ "$run_nd6_fv" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 6  ${ARG}  ${fv_nd6} -o ${OUT}/nd6_rhc_fv_${NAME}_${THROW}.root >& ${OUT}/nd6_rhc_fv_${NAME}_${THROW}.log
  fi
 #### ## WC det Toch
  if [ "$run_nd7" = "true" ]; then 
    ${EXE} -dir $NDRHCDIR -id 7  ${ARG}            -o ${OUT}/nd7_rhc_${NAME}_${THROW}.root >& ${OUT}/nd7_rhc_${NAME}_${THROW}.log
  fi
 #### ## WC det Moz
  if [ "$run_nd8" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 8  ${ARG}            -o ${OUT}/nd8_rhc_${NAME}_${THROW}.root >& ${OUT}/nd8_rhc_${NAME}_${THROW}.log 
  fi

 #### ## x=0 dir
  if [ "$run_nd9" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}            -o ${OUT}/nd9_rhc_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_${NAME}_${THROW}.log
  fi
 #### FVs of height 10m  (overlapping)
  if [ "$run_nd9_fv_h10" = "true" ]; then
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv1_h10} -o ${OUT}/nd9_rhc_fv1_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv1_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv2_h10} -o ${OUT}/nd9_rhc_fv2_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv2_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv3_h10} -o ${OUT}/nd9_rhc_fv3_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv3_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv4_h10} -o ${OUT}/nd9_rhc_fv4_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv4_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv5_h10} -o ${OUT}/nd9_rhc_fv5_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv5_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv6_h10} -o ${OUT}/nd9_rhc_fv6_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv6_h10_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv7_h10} -o ${OUT}/nd9_rhc_fv7_h10_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv7_h10_${NAME}_${THROW}.log     
  fi
 #### FVs of height 7.7m  (not overlapping)
  if [ "$run_nd9_fv_h7p7" = "true" ]; then 
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv1_h7p7} -o ${OUT}/nd9_rhc_fv1_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv1_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv2_h7p7} -o ${OUT}/nd9_rhc_fv2_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv2_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv3_h7p7} -o ${OUT}/nd9_rhc_fv3_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv3_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv4_h7p7} -o ${OUT}/nd9_rhc_fv4_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv4_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv5_h7p7} -o ${OUT}/nd9_rhc_fv5_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv5_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv6_h7p7} -o ${OUT}/nd9_rhc_fv6_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv6_h7p7_${NAME}_${THROW}.log     
    ${EXE} -dir $NDRHCDIR -id 9  ${ARG}  ${fv_nd9_fv7_h7p7} -o ${OUT}/nd9_rhc_fv7_h7p7_${NAME}_${THROW}.root >& ${OUT}/nd9_rhc_fv7_h7p7_${NAME}_${THROW}.log     
  fi 

fi 
 


 #C - 1 : 2km detector
 #C - 2 : Surface WC Detector
 #C - 3 : INGRID horizontal module
 #C - 4 : INGRID vetical module
 #C - 5 : ND280 off-axis cargo
 #C - 6 : ND280 off-axis magnet
 #C - 7 : WC Detector 0.8-4.2 degrees, Tochibora Direction
 #C - 8 : WC Detector 0.8-4.2 degrees, Mozumi Direction
 #C - 9 : WC Detector 0.8-4.2 degrees, x=0 Direction

