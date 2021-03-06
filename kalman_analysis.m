function kalman_analysis
  Ix = 1;
  Iy = 1;
  Iz = 0.1;
  mass = 10;
  
  F = [0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0;
       0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0;
       0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0;
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0; 
       0, −9.81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
       9.81, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
       0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
       0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0;
       0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0;
       0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0];

  B = [0, 0, 0, 0;
       0, 0, 0, 0;
       0, 0, 0, 0;
       0, 1/Ix, 0, 0;
       0, 0, 1/Iy, 0;
       0, 0, 0, 1/Iz;
       0, 0, 0, 0;
       0, 0, 0, 0;
       1/mass, 0, 0, 0;
       0, 0, 0, 0;
       0, 0, 0, 0;
       0, 0, 0, 0];
       
  H = [1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
        0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0;
        0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0;
        0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0;
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0;
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1];

  Q = eye(12) * 0.5;
  P = eye(12);
  R = eye(6) * 0.3;
endfunction



