create (p1: Professor{name: 'X'}), (p2: Professor{name: 'Y'}), (p3: Professor{name: 'Z'}), (p4: Professor{name: 'W'}), (p5: Professor{name: 'V'})  return p1, p2 ,p3, p4, p5;
create (d1: Department{name: 'CS'}), (d2: Department{name: 'ECE'}), (d3: Department{name: 'DS'}), (d4: Department{name: 'ME'}) return d1, d2, d3, d4;
match (p1:Professor), (d1:Department) where p1.name = 'X' and d1.name = 'CS' create (p1)-[:worksfor]->(d1) return p1, d1;
match (p2:Professor), (d2:Department) where p2.name = 'Y' and d2.name = 'ECE' create (p2)-[:worksfor]->(d2) return p2, d2;
match (p2:Professor), (d2:Department) where p2.name = 'Z' and d2.name = 'CS' create (p2)-[:worksfor]->(d2) return p2, d2;

match (p2:Professor), (d2:Department) where p2.name = 'W' and d2.name = 'ME' create (p2)-[:worksfor]->(d2) return p2, d2;
match (p2:Professor), (d2:Department) where p2.name = 'V' and d2.name = 'DS' create (p2)-[:worksfor]->(d2) return p2, d2;
match (p:Professor)-[r:worksfor]->(d:Department)
where d.name = 'ECE'
set r.joiningdate = date('2024-03-15')
return p, r, d;
match (p:Professor)-[r:WORKSFOR]->(d:Department {name: 'ECE'})
remove r.joiningdate
delete r;