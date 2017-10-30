// -------------------------------------------------------------- -*- C++ -*-
// File: Model1.cpp
// Version 12.2  
// --------------------------------------------------------------------------
// Copyright Hesam Shams (hshams@utk.edu) 2013. All Rights Reserved.
//
// --------------------------------------------------------------------------
//
// Model1.cpp, is a computer programming for the Mathematical Model 1 proposed by Shams and Salmasi
//  Shams, Hesam, and Nasser Salmasi. "Parallel machine scheduling problem with preemptive jobs and
//  transportation delay." Computers & Operations Research 50 (2014): 14-23.
//  The idea is to solve the problem and report the objective function value and time for solving the problem

#include <ilcplex/ilocplex.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include<string.h>
#include <iostream>
ILOSTLBEGIN

int main()
{
	system("cls");
	FILE *TD;
	FILE *pj;
	FILE *m_file;
	FILE *n_file;

	int machine_cat,job_cat,m, n, delay, PT, sample_case,max_sample_case,min_sample_case,Cmax_sol;
	int example_no,class_no,temp_q,temp_t;
	int temp1, temp2;
	char temp_char1[10], temp_char2[10];


	char machine_path[48]   = "C:\\Class\\Machine1\\Job1\\PT1\\01\\Machines.txt";
	char job_path[46]       = "C:\\Class\\Machine1\\Job1\\PT1\\01\\Jobs.txt";
	char transport_path[61] = "C:\\Class\\Machine1\\Job1\\PT1\\01\\TransportationDelay.txt";
	char process_path[56]   = "C:\\Class\\Machine1\\Job1\\PT1\\01\\ProcessingTime.txt";
	char time_path[47]      = "C:\\Class\\Machine1\\Job1\\PT1\\01\\Time2.txt";
	char obj_path[57]       = "C:\\Class\\Machine1\\Job1\\PT1\\01\\ObjectiveValue2.txt";
	char t_path[57]         = "C:\\Class\\Machine1\\Job1\\PT1\\01\\t_jki2.txt";
	char q_path[57]         = "C:\\Class\\Machine1\\Job1\\PT1\\01\\q_jki2.txt";

	printf("\nPlease Enter the Category of Machines :  ");
	scanf("%d",&machine_cat);
	printf("\nPlease Enter the Category of Jobs :  ");
	scanf("%d",&job_cat);
	printf("\nPlease Enter the Range Category:  ");
	scanf("%d",&PT);
	printf("\nPlease Enter the Min Example:  ");
	scanf("%d",&min_sample_case);
	printf("\nPlease Enter the Max Example:  ");
	scanf("%d",&max_sample_case);
	
	switch(machine_cat){
		case 1:
			machine_path[16]   = '1';
			job_path[16]       = '1';
			transport_path[16] = '1';
            process_path[16]   = '1';
			time_path[16]      = '1';
            obj_path[16]       = '1';
			t_path[16]         = '1';
			q_path[16]         = '1';
			break;
			
		case 2:
			machine_path[16]   = '2';
			job_path[16]       = '2';
			transport_path[16] = '2';
            process_path[16]   = '2';
			time_path[16]      = '2';
            obj_path[16]       = '2';
			t_path[16]         = '2';
			q_path[16]         = '2';
			break;
			
		case 3:
			machine_path[16]   = '3';
			job_path[16]       = '3';
			transport_path[16] = '3';
            process_path[16]   = '3';
			time_path[16]      = '3';
            obj_path[16]       = '3';
			t_path[16]         = '3';
			q_path[16]         = '3';
			break;
			
		default:
			printf("\nValue is UNKNOWN");
			getch();
			exit (-1);
	}
	
	switch(job_cat){
		case 1:
			machine_path[21]   = '1';
			job_path[21]       = '1';
			transport_path[21] = '1';
            process_path[21]   = '1';
			time_path[21]      = '1';
            obj_path[21]       = '1';
			t_path[21]         = '1';
			q_path[21]         = '1';
			break;
			
		case 2:
			machine_path[21]   = '2';
			job_path[21]       = '2';
			transport_path[21] = '2';
            process_path[21]   = '2';
			time_path[21]      = '2';
            obj_path[21]       = '2';
			t_path[21]         = '2';
			q_path[21]         = '2';
			break;
			
		case 3:
			machine_path[21]   = '3';
			job_path[21]       = '3';
			transport_path[21] = '3';
            process_path[21]   = '3';
			time_path[21]      = '3';
            obj_path[21]       = '3';
			t_path[21]         = '3';
			q_path[21]         = '3';
			break;
			
		default:
			printf("\nValue is UNKNOWN");
			getch();
			exit (-1);
	}

	switch(PT){
		case 1:
			machine_path[25]   = '1';
			job_path[25]       = '1';
			transport_path[25] = '1';
            process_path[25]   = '1';
			time_path[25]      = '1';
            obj_path[25]       = '1';
			t_path[25]         = '1';
			q_path[25]         = '1';
			break;
			
		case 2:
			machine_path[25]   = '2';
			job_path[25]       = '2';
			transport_path[25] = '2';
            process_path[25]   = '2';
			time_path[25]      = '2';
            obj_path[25]       = '2';
			t_path[25]         = '2';
			q_path[25]         = '2';
			break;
			
		case 3:
			machine_path[25]   = '3';
			job_path[25]       = '3';
			transport_path[25] = '3';
            process_path[25]   = '3';
			time_path[25]      = '3';
            obj_path[25]       = '3';
			t_path[25]         = '3';
			q_path[25]         = '3';
			break;
			
		default:
			printf("\nValue is UNKNOWN");
			getch();
			exit (-1);
	}

	for (sample_case = min_sample_case; sample_case <= max_sample_case; sample_case++){
		temp1 = int(sample_case/10);
		temp2 = int(sample_case - temp1*10);
		sprintf(temp_char1,"%d",temp1);
		sprintf(temp_char2,"%d",temp2);

		machine_path[27]   = temp_char1[0];
		job_path[27]       = temp_char1[0];
		transport_path[27] = temp_char1[0];
		process_path[27]   = temp_char1[0];
		time_path[27]      = temp_char1[0];
		obj_path[27]       = temp_char1[0];
		t_path[27]         = temp_char1[0];
		q_path[27]         = temp_char1[0];

		machine_path[28]   = temp_char2[0];
		job_path[28]       = temp_char2[0];
		transport_path[28] = temp_char2[0];
		process_path[28]   = temp_char2[0];
		time_path[28]      = temp_char2[0];
		obj_path[28]       = temp_char2[0];
		t_path[28]         = temp_char2[0];
		q_path[28]         = temp_char2[0];


		

		printf("\n%s",transport_path);
		printf("\n%s",process_path);

	/****************************************/
		m_file = fopen(machine_path,"r");
		if(m_file == NULL){
			printf("\nError: File couldn't be opened\n");
			getch();
			exit(-1);
		}
	/* Read Number of Machines*/
		fscanf(m_file, "%d",&m);
		fclose(m_file);

	/****************************************/
		n_file = fopen(job_path,"r");
		if(n_file == NULL){
			printf("\nError: File couldn't be opened\n");
			getch();
			exit(-1);
		}
	/* Read Number of Jobs*/
		fscanf(n_file, "%d",&n);
		fclose(n_file);



	/****************************************/
		TD = fopen(transport_path,"r");
		if(TD == NULL){
			printf("\nError: File couldn't be opened\n");
			getch();
			exit(-1);
		}
	/* Read Transportation Delay*/
		fscanf(TD, "%d",&delay);
		fclose(TD);


	/****************************************/
		int *p = new int [n];

		pj = fopen(process_path,"r");
		if(pj == NULL){
			printf("\nError: File couldn't be opened\n");
			getch();
			exit(-1);
		}
	/* Put data in p Variable.*/
		for(int j = 0; j < n; j++)
			fscanf(pj, "%d",&p[j]);			
		fclose(pj);

		double max_part = (m - 1)/2 + 1;
		int U = (int) max_part;

		int BigM = 0;

		for(int i = 0; i < n; i++)
			BigM = BigM + p[i];
		BigM = BigM + delay;



	   IloEnv   env;
	   try {
		  IloModel model(env);

		  typedef IloArray<IloNumVarArray> DimVar2;
		  typedef IloArray<DimVar2> DimVar3;
		  typedef IloArray<DimVar3> DimVar4;
		  typedef IloArray<DimVar4> DimVar5;
		  typedef IloArray<DimVar5> DimVar6;

		  //Decision Variables
		  //************************************************************
		  //Cmax: Makespan
		  IloNumVar Cmax(env, 0, +IloInfinity, ILOINT);


		  //q[j][k][i]: the kth part of job j is processed on machine i
		  DimVar3 q(env,n);
		  for(int j=0; j<n; j++){
			  q[j] = DimVar2(env,U);
			  for(int k=0; k<U; k++){
				  q[j][k] = IloNumVarArray(env,m);
				  for(int i=0; i<m; i++){
					  q[j][k][i] = IloNumVar(env, 0, +IloInfinity, ILOINT);
				  }
			  }
		  }

		  //t[j][k][i]: the start time of processing the kth part of job j is processed on machine i
		  DimVar3 t(env,n);
		  for(int j=0; j<n; j++){
			  t[j] = DimVar2(env,U);
			  for(int k=0; k<U; k++){
				  t[j][k] = IloNumVarArray(env,m);
				  for(int i=0; i<m; i++){
					  t[j][k][i] = IloNumVar(env, 0, +IloInfinity, ILOINT);
				  }
			  }
		  }


		  //x[j][k][i]: is equal to 1 ifthe kth part of job j is processed on machine i
		  //          : is equal to 0 otherwise
		  DimVar3 x(env,n);
		  for(int j=0; j<n; j++){
			  x[j] = DimVar2(env,U);
			  for(int k=0; k<U; k++){
				  x[j][k] = IloNumVarArray(env,m);
				  for(int i=0; i<m; i++){
					  x[j][k][i] = IloNumVar(env, 0, 1, ILOINT);
				  }
			  }
		  }


		  //Alpha[j][k][i][j'][k'][i']: is equal to 1 if the process of the kth part of job j on machine i is completed before the process of the k'th part of job j' on machine i' is started
		  //                          : otherwise
		  DimVar6 Alpha(env,n);
		  for(int j=0; j<n; j++){
			  Alpha[j] = DimVar5(env,U);
			  for(int k=0; k<U; k++){
				  Alpha[j][k] = DimVar4(env,m);
				  for(int i=0; i<m; i++){
					  Alpha[j][k][i] = DimVar3(env,n);
					  for(int jj=0; jj<n; jj++){
						  Alpha[j][k][i][jj] = DimVar2(env,U);
						  for(int kk=0; kk<U; kk++){
							  Alpha[j][k][i][jj][kk] = IloNumVarArray(env,m);
							  for(int ii=0; ii<m; ii++){
								  Alpha[j][k][i][jj][kk][ii] = IloNumVar(env, 0, 1, ILOINT);
							  }
						  }
					  }
				  }
			  }
		  }

		  //Objective Function
		  //(equation 12)
		  model.add(IloMinimize(env, Cmax));

		  //Constraint: the sum of processing time of each job on all machines is equal to its required processing time
		  //(equation 13)
		  for(int j=0; j<n; j++){
			  IloExpr sum_over_i_k(env);
			  for(int i=0; i<m; i++){
				  for(int k=0; k<U; k++){
					  sum_over_i_k += q[j][k][i];
				  }
			  }
			  model.add(sum_over_i_k == p[j]);
			  sum_over_i_k.end();
		  }

		  //Constraint: the sum of processing time of each job on all machines is less than or equal to makespan
		  //(equation 14)
		  for(int i=0; i<m; i++){
			  IloExpr sum_over_j_k(env);
			  for(int j=0; j<n; j++){
				  for(int k=0; k<U; k++){
					  sum_over_j_k += q[j][k][i];
				  }
			  }
			  model.add(sum_over_j_k - Cmax <= 0);
			  sum_over_j_k.end();
		  }

		  //Constraint: the makespan value should be greater than or equal to the completion time of each processed part of each job on any machine
		  //(equation 15)
		  for(int j=0; j<n; j++){
			  for(int k=0; k<U; k++){
				  for(int i=0; i<m; i++){
					  model.add(t[j][k][i] + q[j][k][i] - Cmax <= 0);
				  }
			  }
		  }

		  //Constraint Set: each machine is processing at most one job at any time
		  //(equation 16)
		  for(int j=0; j<n; j++){
			  for(int k=0; k<U; k++){
				  for(int i=0; i<m; i++){
					  for(int jj=0; jj<n; jj++){
						  if (j != jj){
							  model.add(t[j][k][i] + q[j][k][i] - t[jj][k][i] + BigM*Alpha[j][k][i][jj][k][i] <= BigM);
							  model.add(t[jj][k][i] + q[jj][k][i] - t[j][k][i] - BigM*Alpha[j][k][i][jj][k][i] <= 0);
							  model.add(Alpha[j][k][i][jj][k][i] + Alpha[jj][k][i][j][k][i] == 1);
						  }
					  }
				  }
			  }
		  }

		  //Constraint Set: each machine is processing at most one job at any time
		  //(equation 17)
		  for(int j=0; j<n; j++){
			  for(int k=0; k<U; k++){
				  for(int i=0; i<m; i++){
					  for(int kk=0; kk<U; kk++){
						  if (k != kk){
							  model.add(t[j][k][i] + q[j][k][i] - t[j][kk][i] + BigM*Alpha[j][k][i][j][kk][i] <= BigM);
							  model.add(t[j][kk][i] + q[j][kk][i] - t[j][k][i] - BigM*Alpha[j][k][i][j][kk][i] <= 0);
							  model.add(Alpha[j][k][i][j][kk][i] + Alpha[j][kk][i][j][k][i] == 1);
						  }
					  }
				  }
			  }
		  }

		  //Constraint Set: each machine is processing at most one job at any time
		  //(equation 18)
		  for(int j=0; j<n; j++){
			  for(int k=0; k<U; k++){
				  for(int i=0; i<m; i++){
					  for(int ii=0; ii<m; ii++){
						  for(int kk=0; kk<U; kk++){
							  
								  if (i != ii){
									  model.add(t[j][k][i] + q[j][k][i] - t[j][kk][ii] + BigM*Alpha[j][k][i][j][kk][ii] <= BigM);
									  model.add(t[j][kk][ii] + q[j][kk][ii] - t[j][k][i] - BigM*Alpha[j][k][i][j][kk][ii] <= 0);
									  model.add(Alpha[j][k][i][j][kk][ii] + Alpha[j][kk][ii][j][k][i] == 1);
								  }
							  
						  }
					  }
				  }
			  }
		  }
		  //Constraint Set: calculate the transportation delays for transported jobs
		  //(equation 19)
		  for(int j=0; j<n; j++){
			  for(int k=0; k<U; k++){
				  for(int i=0; i<m; i++){
					  for(int ii=0; ii<m; ii++){
						  for(int kk=0; kk<U; kk++){
							  
								  if (i != ii){
									  model.add(t[j][k][i] + q[j][k][i] + delay*x[j][k][i] + BigM*Alpha[j][k][i][j][kk][ii] - t[j][kk][ii] <= BigM);
									  model.add(t[j][kk][ii] + q[j][kk][ii] + delay*x[j][kk][ii] - BigM*Alpha[j][k][i][j][kk][ii] - t[j][k][i] <= 0);
									  model.add(Alpha[j][k][i][j][kk][ii] + Alpha[j][kk][ii][j][k][i] == 1);
								  }
							  
						  }
					  }
				  }
			  }
		  }


		  //Constraint Set: find the jobs processed on each machine
		  //(equation 20)
		  for(int j=0; j<n; j++){
			  for(int k=0; k<U; k++){
				  for(int i=0; i<m; i++){
					  model.add(x[j][k][i] - BigM*q[j][k][i] <= 0);
					  model.add(q[j][k][i] - BigM*x[j][k][i] <= 0);
				  }
			  }
		  }



		  IloCplex cplex(model);
		  cplex.setParam(IloCplex::SimDisplay, 2);
		  cplex.setParam(IloCplex::RootAlg, IloCplex::Network);

		  time_t start, end;
		  double total_time;
		  start = clock();

		  cplex.solve();

		  end = clock();
		  total_time = (double)( end - start )/(double)CLK_TCK ;
		  printf( "\nC++ Time (saved time) : %0.3f \n", total_time );
		  cplex.out() << "After network optimization, objective is "
					  << cplex.getObjValue() << endl;


		  IloNumArray vals(env);

		  cplex.out() << "Solution status " << cplex.getStatus() << endl;
		  cplex.out() << "Objective value " << cplex.getObjValue() << endl;



		  FILE *solutiontime;
		  FILE *objval;

		  Cmax_sol = int(cplex.getValue(Cmax)+0.5);

		  objval = fopen(obj_path,"w");
		  fprintf(objval, "%d",Cmax_sol);
		  fclose(objval);

		  solutiontime = fopen(time_path,"w");
		  fprintf(solutiontime, "%f",total_time);
		  fclose(solutiontime);

		  FILE *tjki_val;
		  FILE *qjki_val;

		  tjki_val = fopen(t_path,"w");
		  qjki_val = fopen(q_path,"w");

		for(int j=0; j<n; j++){
			for(int k=0;  k<U; k++){
				for(int i=0; i<m; i++){
					temp_q = int(cplex.getValue(q[j][k][i])+0.5);
					temp_t = int(cplex.getValue(t[j][k][i])+0.5);
					fprintf(tjki_val, "%d\n",temp_t);
					fprintf(qjki_val, "%d\n",temp_q);

				}
			}
		}

		fclose(tjki_val);
		fclose(qjki_val);


		  
		  cplex.exportModel("Model2.lp");
	   }
	   catch (IloException& e) {
		  cerr << "Concert exception caught: " << e << endl;

		  FILE *solutiontime;
		  FILE *objval;
		  objval = fopen(obj_path,"w");
		  fprintf(objval, "%s","Out of Memory");
		  fclose(objval);

		  solutiontime = fopen(time_path,"w");
		  fprintf(solutiontime, "%s","Out of Memory");
		  fclose(solutiontime);
	   }
	   catch (...) {
		  cerr << "Unknown exception caught" << endl;
		  
		  FILE *solutiontime;
		  FILE *objval;
		  objval = fopen(obj_path,"w");
		  fprintf(objval, "%s","Out of Memory");
		  fclose(objval);

		  solutiontime = fopen(time_path,"w");
		  fprintf(solutiontime, "%s","Out of Memory");
		  fclose(solutiontime);
	   }

	   env.end();
	   
	   delete [] p;
	   }

   getch();
   return 0;
} // END main
