https :			// paiza.io/projects/HMByJQkiYKhayg-5wTATyA?language=mysql
		https : // paiza.io/projects/HMByJQkiYKhayg-5wTATyA?language=mysql
				create table
				Customer2(Cust_id int(11), Name varchar(20), total_pur int(11));

insert into Customer2 values(1, 'Nachi', 1000);
insert into Customer2 values(2, 'Abhi', 2000);
insert into Customer2 values(3, 'Rishi', 3000);
insert into Customer2 values(4, 'Tushar', 4999);
insert into Customer2 values(5, 'Abhay', 5000);
insert into Customer2 values(6, 'Mahesh', 10000);
insert into Customer2 values(7, 'Yash', 15000);
insert into Customer2 values(8, 'Anurag', 20000);
insert into Customer2 values(9, 'Kevin', 20000);

create table Category(Cust_id int(11), Name varchar(20), category varchar(20));

select* from Customer2;
delimiter $$ create procedure Cat() begin declare name varchar(30);
declare b int default 0;
declare id int;
declare total int;
			declare cursor_c1 cursor for select * from Customer2;
			declare continue handler for not found set b=1;
			open cursor_c1;
			repeat fetch cursor_c1 into id, name, total;
			if
				not b then if total >= 10000 and total <= 20000 then insert into Category values(id, name, 'Platinum');
			end if;
			if total
				>= 5000 and total <= 9999 then insert into Category values(id, name, 'Gold');
			end if;
			if total
				>= 2000 and total <= 4999 then insert into Category values(id, name, 'Silver');
			end if;
			end if;
			until b end repeat;
			end;
			$$ delimiter;
			call Cat();

			select* from Category;
