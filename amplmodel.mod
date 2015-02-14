# PART 1 DECLARATION OF VARIABLES (variables, parameters, sets etc) 
param imin;
param imax;
param jmin;
param jmax;
set I := {imin..imax};
set J := {jmin..jmax};
param D{I, J};
set N := {1..2};
param B;
param r;

var ED{I,J};
var ES{I,J};
var S{I,J};
# PART 2 OBJECTIVE FUNCTION: name and mathematical expression 
minimize Equation : sum {i in I} sum {j in J} (ED[i,j]+ES[i,j]) ;

# PART 3 CONSTRAINTS: names and corresponding mathematical expressions 
#subject to Sij { i in I, j in J }: S[i,j] = sum {x in 1..X} sum {y in 1..Y} ((P[x,y]/r^2) * cos(atan(sqrt((i-x)^2+(j-y)^2)/r)));
# Contrainte précédente à modifier.

subject to EDMin  { i in I, j in J } : 1 >= 0;
subject to ESMin  { i in I, j in J } : ES[i,j] >= 0;
subject to EDdiff { i in I, j in J } : ED[i,j] >= (D[i,j] - S[i,j]);
subject to ESdiff { i in I, j in J } : ES[i,j] >= (S[i,j] - D[i,j]);
