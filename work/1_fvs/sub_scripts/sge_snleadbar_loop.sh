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


# This file:  sge_snleadbar_loop.sh
# Loops through number of flux throws
# For each flux throw submits an instance of sge_snleadbar_job.sh
# e.g.
#      ./sge_snleadbar_loop.sh 500


## XXX --- set source file for SGE batch system if required XXX --- ##

  SGE_SOURCE=true
  SGE=/opt/sge/default/common/settings.sh

## ---------------------------------------------------------------- ##



#  source SGE settings 
if [ -z "$SGE_CLUSTER_NAME" ] ; then 
  if [ "${SGE_SOURCE}" = "true" ]; then
    source ${SGE}
  fi
fi

# record job subs in a log file
LOG=./qsub.log
echo "$0 Starting at $(date)" >>$LOG


#let "N=$1-1"

#for i in $(seq 0 $N)
for i in $(seq 0 1)
do 
  echo qsub -q sge_snleadbar_job.sh $i  >>$LOG
  qsub -l h_rss=2G,h_vmem=2G  -q SL6 sge_snleadbar_job.sh $i  |tee -a $LOG
done


