-- Last updated: 3/18/2026, 2:29:28 PM
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
    set N = N-1;
  RETURN (
     select distinct salary from employee order by salary desc limit 1 offset N

  );
END