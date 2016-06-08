#
# CS2110 Testbench
# Runs tests

TEST_DIR=tests
TEST_COUNT=5
PROGS=( mergesort quicksort insertionsort selectionsort )
ARGS=

j=0
total=0

for prog in "${PROGS[@]}"; do
    for i in `seq 1 $TEST_COUNT`; do
        total=$((total+1))
        echo -n "Running Test $i... "
        inp="in-$i";
        outp="out-$i";
        outp_="out-${i}_";
        ./$prog $ARGS < $TEST_DIR/$inp > $TEST_DIR/$outp_;
        diff -bBq $TEST_DIR/$outp $TEST_DIR/$outp_ > /dev/null;
        if [[ $? == 0 ]] ; then
            echo "Passed."
            j=$((j+1))
        else
            echo "Failed."
        fi
    done;
done;
echo "Done ($j/$total) passed."