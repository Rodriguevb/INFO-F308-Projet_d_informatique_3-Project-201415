# PART 1 DECLARATION OF VARIABLES (variables, parameters, sets etc) 
param imin;
param imax;
param jmin;
param jmax;
set I;
set J;
param D{I, J};
set N;
param B;
param r;

var ED;
var ES;
var S{I,J};
# PART 2 OBJECTIVE FUNCTION: name and mathematical expression 
minimize Equation : sum {i in I} sum {j in J} (ED[i,j]+ES[i,j]) ;

# PART 3 CONSTRAINTS: names and corresponding mathematical expressions 
subject to Sij : S[i,j] = sum {x in 1..X} sum {y in 1..Y} ((P[x,y]/r^2) * cos(atan(sqrt((i-x)^2+(j-y)^2)/r)));

subject to EDMin : ED[i,j] >= 0;
subject to ESMin : ES[i,j] >= 0;
subject to EDdiff: ED[i,j] >= (D[i,j] - S[i,j]);
subject to ESdiff: ES[i,j] >= (S[i,j] - D[i,j]);
