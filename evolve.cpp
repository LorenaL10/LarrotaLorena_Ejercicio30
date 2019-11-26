#include <iostream>
#include <fstream>
#include <cmath>
#include "stdio.h"

void init(double *psi, int n_x);
void print(double *psi, int n_x);
void copy(double *recibe, double *entrega, int n_x);
void evolve(double *psi_new, double *psi_old, double delta_t, double delta_x, int n_x);

int main(int argc, char **argv){
  double *psi = NULL;
  double *psi_past = NULL;
  int n_x;
  int n_tmax;
  int n;
  double t_max=1.0;
  double delta_x = 2.0/n_x;
  double delta_t=delta_x*delta_x/2;
    

  n_x=atoi(argv[1]);

  delta_x = 2.0/n_x;
  delta_t = delta_x*delta_x/2;
  
  psi  = new double [n_x];
  psi_past  = new double [n_x];

  init(psi, n_x);
  print(psi, n_x);
  
  for(n=1;n<n_x;n++){
    copy(psi_past, psi, n_x);
    evolve(psi, psi_past, delta_t, delta_x, n_x);
    print(psi, n_x);
  }

  return 0;
}

void evolve(double *psi_new, double *psi_old, double delta_t, double delta_x, int n_x){
  int i;
  double s=1.0;
  double epsilon;
  double epsilon1=0.0;
 
  for(i=1;i<n_x-1;i++){
    psi_new[i] = psi_old[i];
    psi_new[i] += (psi_old[i]) * ((psi_old[i+1]/2)-psi_old[i] + (psi_old[i-1]/2)+(s*delta_x*delta_x/2));
    psi_new[i] += delta_t * s;
    epsilon1=abs(psi_new[i]-psi_old[i]);
    if (epsilon1>epsilon){
        epsilon=epsilon1;
    }
  }
  
}

void copy(double *recibe, double *entrega, int n_x){
  int i;
  for (i=0;i<n_x;i++){
    recibe[i] = entrega[i];
  }
}

void init(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    psi[i] = 0.0;
  }
}


void print(double *psi, int n_x){
  int i;
  for(i=0;i<n_x;i++){
    std::cout << psi[i] << " ";
  }
  std::cout << "\n";
}


