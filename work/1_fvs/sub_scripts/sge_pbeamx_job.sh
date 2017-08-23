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


## This file:  sge_pbeamx_job.sh
## Sets pbeamx inputs for flux_throws 


 # --------------------- #
 # For systematic:  pbeamx #

  export THROW=${1}
  echo THROW = ${THROW}
  export FOLDER="pbeamx_outputs"
  export NAME="PBEAMX"
  export ARG="-type PBEAMX  -epbeam 0.4  -throw ${THROW}"
 # --------------------- #

 
 ./sge_job_framework.sh
