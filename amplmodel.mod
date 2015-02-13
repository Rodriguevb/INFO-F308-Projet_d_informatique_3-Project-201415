# PART 1 DECLARATION OF VARIABLES (variables, parameters, sets etc) 
var ED;
var ES;
var S;
# PART 2 OBJECTIVE FUNCTION: name and mathematical expression 
minimize Equation : sum {i in 1..n} sum {j in 1..n} (ED[i][j]+ES[i][j]) ;

# PART 3 CONSTRAINTS: names and corresponding mathematical expressions 
subject to S[i][j] : S[i][j] = sum {x in 1..X} sum {y in 1..Y} ((P[x][y]/r^2) * cos(atan(sqrt((i-x)^2+(j-y)^2)/r)));

subject to EDMin : ED[i][j] >= 0;
subject to ESMin : ES[i][j] >= 0;
subject to EDdiff: ED[i][j] >= (D[i][j] - S[i][j]);
subject to ESdiff: ES[i][j] >= (S[i][j] - D[i][j]);
