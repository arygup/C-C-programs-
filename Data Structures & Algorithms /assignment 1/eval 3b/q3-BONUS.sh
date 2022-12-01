mkdir tests_3
cd tests_3

wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/1_bonus.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/2_bonus.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/3_bonus.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/4_bonus.in
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/5_bonus.in

wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/1_bonus.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/2_bonus.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/3_bonus.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/4_bonus.out
wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/tests_3/5_bonus.out

cd ..

wget https://raw.githubusercontent.com/kjain1810/DSA-Spring-22/master/assignment1/driver_bonus.c

gcc *.c -g -o q3.out


./q3.out < tests_3/1_bonus.in > tests_3/sub_1.out
./q3.out < tests_3/2_bonus.in > tests_3/sub_2.out
./q3.out < tests_3/3_bonus.in > tests_3/sub_3.out
./q3.out < tests_3/4_bonus.in > tests_3/sub_4.out
./q3.out < tests_3/5_bonus.in > tests_3/sub_5.out

cmp --silent tests_3/1_bonus.out tests_3/sub_1.out && echo '### Test 1 PASSED ###' || echo '### Test 1 FAILED ###'
cmp --silent tests_3/2_bonus.out tests_3/sub_2.out && echo '### Test 2 PASSED ###' || echo '### Test 2 FAILED ###'
cmp --silent tests_3/3_bonus.out tests_3/sub_3.out && echo '### Test 3 PASSED ###' || echo '### Test 3 FAILED ###'
cmp --silent tests_3/4_bonus.out tests_3/sub_4.out && echo '### Test 4 PASSED ###' || echo '### Test 4 FAILED ###'
cmp --silent tests_3/5_bonus.out tests_3/sub_5.out && echo '### Test 5 PASSED ###' || echo '### Test 5 FAILED ###'