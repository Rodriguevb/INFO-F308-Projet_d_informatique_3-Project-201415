# PART 1 DECLARATION OF VARIABLES (variables, parameters, sets etc) 
param imin;
param imax;
param jmin;
param jmax;
param nmax;
set I := {imin..imax};
set J := {jmin..jmax};
param D{I, J};
set N := {1..nmax};
param B;
param r;
param UB;

var S{I,J};
var X{N} integer;
var Y{N} integer;
var P{N} integer;
var Sin{I, N};
var Sjn{J, N};
var Sijn{I, J, N};
# PART 2 OBJECTIVE FUNCTION: name and mathematical expression 
minimize Equation : sum {i in I} sum {j in J} abs( D[i,j] - S[i,j]) ;

# PART 3 CONSTRAINTS: names and corresponding mathematical expressions 

# Contrainte sur Xn et Yn
subject to Xmin { n in N } : X[n] >= imin + B;
subject to Xmax { n in N } : X[n] <= imax + B;

subject to Ymin { n in N } : Y[n] >= jmin + B;
subject to Ymax { n in N } : Y[n] <= jmax + B;

# Contrainte sur Pn
subject to Pmin { n in N } : P[n] >= 0;
subject to Pmax { n in N } : P[n] <= UB;

# Contrainte Sin / Sjn / Sijn:
subject to Sinc { n in N , i in I} : Sin[i,n] = ( P[n] / (r*r) ) * cos( atan( abs(i - X[n]) / r ) );
subject to Sjnc { n in N , j in J} : Sjn[j,n] = ( P[n] / (r*r) ) * cos( atan( abs(j - Y[n]) / r ) );
subject to Sijnc { n in N, i in I, j in J} : Sijn[i,j,n] = min(Sin[i,n], Sjn[j,n]);
subject to Sij { i in I, j in J} : S[i,j] = sum { n in N } Sijn[i,j,n];