#include "gurobi_c++.h"
using namespace std;

int main(int argc, char *argv[])
{
	try{
		GRBEnv env= GRBEnv(true);
		env.set("LogFile","set.log");
		env.start();

		GRBModel model=GRBModel(env);

		GRBVar a_1=model.addVar(0.0,1.0,0.0,GRB_BINARY,"a_1");
		GRBVar b_1=model.addVar(0.0,1.0,0.0,GRB_BINARY,"b_1");
		GRBVar a_2=model.addVar(0.0,1.0,0.0,GRB_BINARY,"a_2");
		GRBVar b_2=model.addVar(0.0,1.0,0.0,GRB_BINARY,"b_2");
		GRBVar a_3=model.addVar(0.0,1.0,0.0,GRB_BINARY,"a_3");
		GRBVar b_3=model.addVar(0.0,1.0,0.0,GRB_BINARY,"b_3");
		GRBVar a_4=model.addVar(0.0,1.0,0.0,GRB_BINARY,"a_4");
		GRBVar b_4=model.addVar(0.0,1.0,0.0,GRB_BINARY,"b_4");
		GRBVar a_5=model.addVar(0.0,1.0,0.0,GRB_BINARY,"a_5");
		GRBVar b_5=model.addVar(0.0,1.0,0.0,GRB_BINARY,"b_5");
		GRBVar a_6=model.addVar(0.0,1.0,0.0,GRB_BINARY,"a_6");
		GRBVar b_6=model.addVar(0.0,1.0,0.0,GRB_BINARY,"b_6");
		GRBVar q=model.addVar(0.0,1.0,0.0,GRB_BINARY,"q");

		GRBLinExpr obj;
		int sense;
		model.setObjective(obj,sense);
		model.addConstr(a_1<=b_1-q+1, "c0");
		model.addConstr(a_2<=b_2-q+1, "c1");
		model.addConstr(a_3<=b_3-q+1, "c2");
		model.addConstr(a_4<=b_4-q+1, "c3");
		model.addConstr(a_5<=b_5-q+1, "c4");
		model.addConstr(a_6<=b_6-q+1, "c5");

		model.optimize();

		cout<<a_1.get(GRB_StringAttr_VarName)<<" "
		    <<a_1.get(GRB_DoubleAttr_X)<<endl;	
		cout<<b_1.get(GRB_StringAttr_VarName)<<" "
		    <<b_1.get(GRB_DoubleAttr_X)<<endl;
		cout<<a_2.get(GRB_StringAttr_VarName)<<" "
		    <<a_2.get(GRB_DoubleAttr_X)<<endl;
		cout<<b_2.get(GRB_StringAttr_VarName)<<" "
		    <<b_2.get(GRB_DoubleAttr_X)<<endl;
		cout<<a_3.get(GRB_StringAttr_VarName)<<" "
		    <<a_3.get(GRB_DoubleAttr_X)<<endl;
		cout<<b_3.get(GRB_StringAttr_VarName)<<" "
		    <<b_3.get(GRB_DoubleAttr_X)<<endl;
		cout<<a_4.get(GRB_StringAttr_VarName)<<" "
		    <<a_4.get(GRB_DoubleAttr_X)<<endl;
		cout<<b_4.get(GRB_StringAttr_VarName)<<" "
		    <<b_4.get(GRB_DoubleAttr_X)<<endl;
		cout<<a_5.get(GRB_StringAttr_VarName)<<" "
		    <<a_5.get(GRB_DoubleAttr_X)<<endl;
		cout<<b_5.get(GRB_StringAttr_VarName)<<" "
		    <<b_5.get(GRB_DoubleAttr_X)<<endl;
		cout<<a_6.get(GRB_StringAttr_VarName)<<" "
		    <<a_6.get(GRB_DoubleAttr_X)<<endl;
		cout<<b_6.get(GRB_StringAttr_VarName)<<" "
		    <<b_6.get(GRB_DoubleAttr_X)<<endl;
		cout<<q.get(GRB_StringAttr_VarName)<<" "
		    <<q.get(GRB_DoubleAttr_X)<<endl;

		cout<<"Obj: "<<model.get(GRB_DoubleAttr_ObjVal)<<endl;
	}
		catch(GRBException e){
			cout<<"Error code=" <<e.getErrorCode()<<endl;
			cout<<e.getMessage()<<endl;
		} catch(...){
			cout<<"Exception during optimization"<<endl;
		}

		return 0;
	} 
