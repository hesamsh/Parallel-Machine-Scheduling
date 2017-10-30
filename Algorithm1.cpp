// -------------------------------------------------------------- -*- C++ -*-
// File: Algorithm1.cpp
// Version 12.2  
// --------------------------------------------------------------------------
// Copyright Hesam Shams (hshams@utk.edu) 2013. All Rights Reserved.
//
// --------------------------------------------------------------------------
//
// Algorithm1.cpp, is a computer programming for the Algorithm 1 proposed by Shams and Salmasi
//  Shams, Hesam, and Nasser Salmasi. "Parallel machine scheduling problem with preemptive jobs and
//  transportation delay." Computers & Operations Research 50 (2014): 14-23.
//  The idea is to solve the problem and report the objective function value and time for solving the problem
//  This algorithm, first the optimal schedule, then solve the sequences

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

	int machine_cat,job_cat,m, n, delay, TP, sample_case,max_sample_case,min_sample_case,Cmax_sol;
	int example_no,class_no,min_job_cat,max_job_cat,min_TP,max_TP;
	int temp1, temp2;
	char temp_char1[10], temp_char2[10];
	double total_time1,total_time2,total_time3,total_time4,total_time;
	int check_st;
	check_st = 0;


	char machine_path[48]   = "C:\\Class\\Machine1\\Job1\\PT1\\01\\Machines.txt";
	char job_path[46]       = "C:\\Class\\Machine1\\Job1\\PT1\\01\\Jobs.txt";
	char transport_path[61] = "C:\\Class\\Machine1\\Job1\\PT1\\01\\TransportationDelay.txt";
	char process_path[56]   = "C:\\Class\\Machine1\\Job1\\PT1\\01\\ProcessingTime.txt";
	char time_path[47]      = "C:\\Class\\Machine1\\Job1\\PT1\\01\\Time3.txt";
	char obj_path[57]       = "C:\\Class\\Machine1\\Job1\\PT1\\01\\ObjectiveValue3.txt";
	char t_path[57]         = "C:\\Class\\Machine1\\Job1\\PT1\\01\\t_jki3.txt";
	char q_path[57]         = "C:\\Class\\Machine1\\Job1\\PT1\\01\\q_jki3.txt";

	printf("\nPlease Enter the Category of Machines :  ");
	scanf("%d",&machine_cat);
	printf("\nPlease Enter the Min Category of Jobs :  ");
	scanf("%d",&min_job_cat);
	printf("\nPlease Enter the Max Category of Jobs :  ");
	scanf("%d",&max_job_cat);
	printf("\nPlease Enter the Min Range Category:  ");
	scanf("%d",&min_TP);
	printf("\nPlease Enter the Max Range Category:  ");
	scanf("%d",&max_TP);
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
	
	for(job_cat = min_job_cat; job_cat <= max_job_cat; job_cat++){
		for(TP = min_TP; TP <= max_TP; TP++){
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

	switch(TP){
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

		int ***q_sol;
		q_sol = new int **[n];
		for(int j=0; j<n; j++){
			q_sol[j] = new int *[U];
			for(int k=0; k<U; k++){
				q_sol[j][k] = new int [m];
			}
		}

		int ***t_sol;
		t_sol = new int **[n];
		for(int j=0; j<n; j++){
			t_sol[j] = new int *[U];
			for(int k=0; k<U; k++){
				t_sol[j][k] = new int [m];
			}
		}

		for(int j=0; j<n; j++){
			for(int k=0; k<U; k++){
				for(int i=0; i<m; i++){
					t_sol[j][k][i] = 0;
				}
			}
		}

		int ***x_sol;
		x_sol = new int **[n];
		for(int j=0; j<n; j++){
			x_sol[j] = new int *[U];
			for(int k=0; k<U; k++){
				x_sol[j][k] = new int [m];
			}
		}



		int BigM = 0;

		for(int i = 0; i < n; i++)
			BigM = BigM + p[i];
		BigM = BigM + delay;


		IloEnv   env1;
		try {
		IloModel model_1(env1);

		typedef IloArray<IloNumVarArray> DimVar2;
		typedef IloArray<DimVar2> DimVar3;
		typedef IloArray<DimVar3> DimVar4;
		typedef IloArray<DimVar4> DimVar5;
		typedef IloArray<DimVar5> DimVar6;

		//Decision Variables
		//************************************************************
		//Cmax: Makespan
		IloNumVar Cmax(env1, 0, +IloInfinity, ILOINT);


		//q[j][k][i]: the kth part of job j is processed on machine i
		DimVar3 q(env1,n);
		for(int j=0; j<n; j++){
			q[j] = DimVar2(env1,U);
			for(int k=0; k<U; k++){
				q[j][k] = IloNumVarArray(env1,m);
				for(int i=0; i<m; i++){
					q[j][k][i] = IloNumVar(env1, 0, +IloInfinity, ILOINT);
				}
			}
		}


		//x[j][i]: is equal to 1 ifthe kth part of job j is processed on machine i
		//          : is equal to 0 otherwise
		DimVar2 x(env1,n);
		for(int j=0; j<n; j++){
			x[j] = IloNumVarArray(env1,m);
			for(int i=0; i<m; i++){
				x[j][i] = IloNumVar(env1, 0, 1, ILOINT); 
			}
		}

		//Objective Function
		//(equation 12)
		model_1.add(IloMinimize(env1, Cmax));

		//Constraint: the sum of processing time of each job on all machines is equal to its required processing time
		//(equation 13)
		for(int j=0; j<n; j++){
			IloExpr sum_over_i_k(env1);
			for(int i=0; i<m; i++){
				for(int k=0; k<U; k++){
					sum_over_i_k += q[j][k][i];
				}
			}
			model_1.add(sum_over_i_k == p[j]);
			sum_over_i_k.end();
		}

		//Constraint: the sum of processing time of each job on all machines is less than or equal to makespan
		//(equation 14)
		for(int i=0; i<m; i++){
			IloExpr sum_over_j_k(env1);
			for(int j=0; j<n; j++){
				for(int k=0; k<U; k++){
					sum_over_j_k += q[j][k][i];
				}
			}
			model_1.add(sum_over_j_k - Cmax <= 0);
			sum_over_j_k.end();
		}

		//Constraint Set (24)
		for(int j=0; j<n; j++){
			IloExpr sum_over_i(env1);
			for(int i=0; i<m; i++){
				sum_over_i += delay*x[j][i];
			}
			model_1.add(sum_over_i - Cmax <= delay - p[j]);
			sum_over_i.end();
		}

		//Constraint Set (25)
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				IloExpr sum_over_k_BigM(env1);
				IloExpr sum_over_k(env1);
				for(int k=0; k<U; k++){
					sum_over_k += q[j][k][i];
					sum_over_k_BigM += BigM*q[j][k][i];
				}
				model_1.add(x[j][i] - sum_over_k_BigM <=0);
				model_1.add(sum_over_k - BigM*x[j][i] <= 0);
				sum_over_k_BigM.end();
				sum_over_k.end();
			}
		}



		IloCplex cplex(model_1);
		cplex.setParam(IloCplex::SimDisplay, 2);
		cplex.setParam(IloCplex::RootAlg, IloCplex::Network);

		time_t start, end;
		start = clock();

		cplex.solve();

		end = clock();
		total_time1 = (double)( end - start )/(double)CLK_TCK ;
		printf( "\nC++ Time (saved time) : %0.3f \n", total_time1 );
		cplex.out() << "After network optimization, objective is "
					<< cplex.getObjValue() << endl;


		IloNumArray vals(env1);
		cplex.out() << "Solution status " << cplex.getStatus() << endl;
		cplex.out() << "Objective value " << cplex.getObjValue() << endl;

		FILE *qjki_val;

		qjki_val = fopen(q_path,"w");

		for(int j=0; j<n; j++){
			for(int k=0; k<U; k++){
				for(int i=0; i<m; i++){
					q_sol[j][k][i] = int(cplex.getValue(q[j][k][i])+0.5);
					fprintf(qjki_val, "%d\n",q_sol[j][k][i]);
				}
			}
		}

		fclose(qjki_val);
		Cmax_sol = int(cplex.getValue(Cmax)+0.5);

		//Write Objective Value to File
		  
		FILE *objval;

		objval = fopen(obj_path,"w");
		fprintf(objval, "%d",Cmax_sol);
		fclose(objval);
		cplex.exportModel("Model3_1.lp");
		}
		
		catch (IloException& e) {
			cerr << "Concert exception caught: " << e << endl;
			FILE *objval;
			objval = fopen(obj_path,"w");
			fprintf(objval, "%s","Out of Memory");
			fclose(objval);
			check_st = 1;
		}
		catch (...) {
			cerr << "Unknown exception caught" << endl;
			FILE *solutiontime;

		  solutiontime = fopen(time_path,"w");
		  fprintf(solutiontime, "%s","Out of Memory");
		  fclose(solutiontime);

		  FILE *objval;
			objval = fopen(obj_path,"w");
			fprintf(objval, "%s","Out of Memory");
			fclose(objval);
			check_st = 1;
		}
		
		env1.end();

   ///////////////////////////////////////////////////////////////////////////
   //////////////////////////////////END/////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////


   //////////////////////////////////////////////////////////////////////
   ///////////////////////////Model2 Part 2/////////////////////////////
   /////////////////////////////////////////////////////////////////////
      IloEnv   env2;
   try {
      IloModel model2(env2);

	  typedef IloArray<IloNumVarArray> DimVar2;
	  typedef IloArray<DimVar2> DimVar3;

	  //x[j][k][i]: is equal to 1 ifthe kth part of job j is processed on machine i
	  //          : is equal to 0 otherwise
	  DimVar3 x(env2,n);
	  for(int j=0; j<n; j++){
		  x[j] = DimVar2(env2,U);
		  for(int k=0; k<U; k++){
			  x[j][k] = IloNumVarArray(env2,m);
			  for(int i=0; i<m; i++){
				  x[j][k][i] = IloNumVar(env2, 0, 1, ILOINT);
			  }
		  }
	  }

	  //Objective Function
	  //(equation 12)
	  //model2.add(IloMinimize(env2, Cmax_sol));


	  //Constraint Set: find the jobs processed on each machine
	  //(equation 20)
	  for(int j=0; j<n; j++){
		  for(int k=0; k<U; k++){
			  for(int i=0; i<m; i++){
				  model2.add(x[j][k][i] - BigM*q_sol[j][k][i] <= 0);
				  model2.add(q_sol[j][k][i] - BigM*x[j][k][i] <= 0);
			  }
		  }
	  }



      IloCplex cplex(model2);
      cplex.setParam(IloCplex::SimDisplay, 2);
      cplex.setParam(IloCplex::RootAlg, IloCplex::AutoAlg);

	  time_t start, end;
	  start = clock();

      cplex.solve();

	  end = clock();
	  total_time2 = (double)( end - start )/(double)CLK_TCK ;
	  printf( "\nC++ Time (saved time) : %0.3f \n", total_time2 );
      cplex.out() << "After network optimization, objective is "
                  << cplex.getObjValue() << endl;


      IloNumArray vals(env2);
      cplex.out() << "Solution status " << cplex.getStatus() << endl;
      cplex.out() << "Objective value for XJKI " << cplex.getObjValue() << endl;
	  
		for(int j=0; j<n; j++){
			for(int k=0; k<U; k++){
				for(int i=0; i<m; i++){
					x_sol[j][k][i] = int(cplex.getValue(x[j][k][i])+0.5);
				}
			}
		}


      cplex.exportModel("Model2_2.lp");
   }
   catch (IloException& e) {
      cerr << "Concert exception caught: " << e << endl;
		  FILE *solutiontime;

		  solutiontime = fopen(time_path,"w");
		  fprintf(solutiontime, "%s","Out of Memory");
		  fclose(solutiontime);
		  check_st = 1;
   }
   catch (...) {
      cerr << "Unknown exception caught" << endl;
	  FILE *solutiontime;

		  solutiontime = fopen(time_path,"w");
		  fprintf(solutiontime, "%s","Out of Memory");
		  fclose(solutiontime);
		  check_st = 1;
   }

   env2.end();

   //////////////////////////////////////////////////////////////////////
   ///////////////////////////Model2 Part 3/////////////////////////////
   /////////////////////////////////////////////////////////////////////
      IloEnv   env;
   try {
      IloModel model(env);

	  typedef IloArray<IloNumVarArray> DimVar2;
	  typedef IloArray<DimVar2> DimVar3;
	  typedef IloArray<DimVar3> DimVar4;
	  typedef IloArray<DimVar4> DimVar5;
	  typedef IloArray<DimVar5> DimVar6;


	  //Cmax: Makespan
	  IloNumVar Cmax(env, 0, +IloInfinity, ILOINT);

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



	  //Constraint: the makespan value should be greater than or equal to the completion time of each processed part of each job on any machine
	  //(equation 15)
	  for(int j=0; j<n; j++){
		  for(int k=0; k<U; k++){
			  for(int i=0; i<m; i++){
				  if(q_sol[j][k][i] != 0 && q_sol[j][k][i] < p[j]){
					  model.add(t[j][k][i] + q_sol[j][k][i] - Cmax <= 0);}
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
						  if(q_sol[j][k][i] != 0 && q_sol[jj][k][i] != 0 && q_sol[j][k][i] < p[j] && q_sol[jj][k][i] < p[jj]){
						  model.add(t[j][k][i] + q_sol[j][k][i] - t[jj][k][i] + BigM*Alpha[j][k][i][jj][k][i] <= BigM);
						  model.add(t[jj][k][i] + q_sol[jj][k][i] - t[j][k][i] - BigM*Alpha[j][k][i][jj][k][i] <= 0);
						  model.add(Alpha[j][k][i][jj][k][i] + Alpha[jj][k][i][j][k][i] == 1);}
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
						  if(q_sol[j][k][i] != 0 && q_sol[j][kk][i] != 0 && q_sol[j][k][i] < p[j] && q_sol[j][kk][i] < p[j]){
						  model.add(t[j][k][i] + q_sol[j][k][i] - t[j][kk][i] + BigM*Alpha[j][k][i][j][kk][i] <= BigM);
						  model.add(t[j][kk][i] + q_sol[j][kk][i] - t[j][k][i] - BigM*Alpha[j][k][i][j][kk][i] <= 0);
						  model.add(Alpha[j][k][i][j][kk][i] + Alpha[j][kk][i][j][k][i] == 1);}
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
								  if(q_sol[j][k][i] != 0 && q_sol[j][kk][ii] != 0 && q_sol[j][k][i] < p[j] && q_sol[j][kk][ii] < p[j]){
								  model.add(t[j][k][i] + q_sol[j][k][i] - t[j][kk][ii] + BigM*Alpha[j][k][i][j][kk][ii] <= BigM);
								  model.add(t[j][kk][ii] + q_sol[j][kk][ii] - t[j][k][i] - BigM*Alpha[j][k][i][j][kk][ii] <= 0);
								  model.add(Alpha[j][k][i][j][kk][ii] + Alpha[j][kk][ii][j][k][i] == 1);}
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
								  if(q_sol[j][k][i] != 0 && q_sol[j][kk][ii] != 0 && q_sol[j][k][i] < p[j] && q_sol[j][kk][ii] < p[j]){
								  model.add(t[j][k][i] + q_sol[j][k][i] + delay*x_sol[j][k][i] + BigM*Alpha[j][k][i][j][kk][ii] - t[j][kk][ii] <= BigM);
								  model.add(t[j][kk][ii] + q_sol[j][kk][ii] + delay*x_sol[j][kk][ii] - BigM*Alpha[j][k][i][j][kk][ii] - t[j][k][i] <= 0);
								  model.add(Alpha[j][k][i][j][kk][ii] + Alpha[j][kk][ii][j][k][i] == 1);}
							  }
						  
					  }
				  }
			  }
		  }
	  }


      IloCplex cplex(model);
      cplex.setParam(IloCplex::SimDisplay, 2);
      cplex.setParam(IloCplex::RootAlg, IloCplex::AutoAlg);

	  time_t start, end;
	  start = clock();

      cplex.solve();

	  end = clock();
	  total_time3 = (double)( end - start )/(double)CLK_TCK ;
	  printf( "\nC++ Time (saved time) : %0.3f \n", total_time2 );
      cplex.out() << "After network optimization, objective is "
                  << cplex.getObjValue() << endl;


	  
      IloNumArray vals(env);
      cplex.out() << "Solution status " << cplex.getStatus() << endl;
      cplex.out() << "Objective value " << cplex.getObjValue() << endl;
	  
	  

	  

	  for(int j=0; j<n; j++){
		  for(int k=0; k<U; k++){
			  for(int i=0; i<m; i++){
				  if(q_sol[j][k][i] != 0 && q_sol[j][k][i] < p[j]){
					  t_sol[j][k][i] = int(cplex.getValue(t[j][k][i])+0.5);}
			  }
		  }
	  }



      cplex.exportModel("Model3_3.lp");
   }
   catch (IloException& e) {
      cerr << "Concert exception caught: " << e << endl;

		  FILE *solutiontime;

		  solutiontime = fopen(time_path,"w");
		  fprintf(solutiontime, "%s","Out of Memory");
		  fclose(solutiontime);
		  check_st = 1;
   }
   catch (...) {
      cerr << "Unknown exception caught" << endl;
	  FILE *solutiontime;

		  solutiontime = fopen(time_path,"w");
		  fprintf(solutiontime, "%s","Out of Memory");
		  fclose(solutiontime);
		  check_st = 1;
   }

   env.end();

   ///////////////////////////////////////////////////////////////////////////
   //////////////////////////////////END/////////////////////////////////////
   /////////////////////////////////////////////////////////////////////////

   printf("\n %d    ", Cmax_sol);

   if(check_st == 0){

   int *t_pointer = new int [m];

   time_t start, end;

   start = clock();

   for(int i=0; i<m; i++){
	   t_pointer[i] = 0;
	   for(int j=0; j<n; j++){
		   for(int k=0; k<U; k++){
			   if(q_sol[j][k][i] == p[j]){
				   t_sol[j][k][i] = t_pointer[i];
				   t_pointer[i] = t_pointer[i] + q_sol[j][k][i];
				   printf("\n%d",t_pointer[i]);
			   }
		   }
	   }
   }

   for(int i=0; i<m; i++){
	   for(int j=0; j<n; j++){
		   for(int k=0; k<U; k++){
			   if(q_sol[j][k][i] != 0 && q_sol[j][k][i] < p[j]){
				   for(int jj=0; jj<n; jj++){
					   if (j != jj){
					   for(int kk=0; kk<U; kk++){
						   if (k != kk){
							   if(t_sol[j][k][i] <= t_sol[jj][kk][i]){
								   t_sol[jj][kk][i] = t_sol[jj][kk][i] + q_sol[j][k][i];
								   printf("\n%d",t_sol[jj][kk][i]);
							   }
						   }
					   }
					   }
				   }
			   }
		   }
	   }
   }


   end = clock();
   total_time4 = (double)( end - start )/(double)CLK_TCK ;

   total_time = total_time1 + total_time2 + total_time3 + total_time4;

   FILE *solutiontime;

	  solutiontime = fopen(time_path,"w");
	  fprintf(solutiontime, "%f",total_time);
	  fclose(solutiontime);

	  printf("\nFINAL TOTAL SOLUTION TIME IS: %f\n",total_time);

	FILE *tjki_val;


	tjki_val = fopen(t_path,"w");

	for(int j=0; j<n; j++){
		for(int k=0;  k<U; k++){
			for(int i=0; i<m; i++){

				fprintf(tjki_val, "%d\n",t_sol[j][k][i]);

			}
		}
	}

	fclose(tjki_val);

   }


   delete [] p;

	for(int j=0; j<n; j++){
		for(int k=0; k<U; k++){
			delete [] q_sol[j][k];
		}
		delete [] q_sol[j];
	}
	delete [] q_sol;


	for(int j=0; j<n; j++){
		for(int k=0; k<U; k++){
			delete [] t_sol[j][k];
		}
		delete [] t_sol[j];
	}
	delete [] t_sol;

	for(int j=0; j<n; j++){
		for(int k=0; k<U; k++){
			delete [] x_sol[j][k];
		}
		delete [] x_sol[j];
	}
	delete [] x_sol;
	   }

	   }
	   }

	   printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\nTHIS THE END!!!!");
   getch();
   return 0;
} // END main
