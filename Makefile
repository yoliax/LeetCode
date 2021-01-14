n:=0
dirname:=tmp

all:${n}*.cpp
	@if [ ! -d ${dirname}  ];then mkdir ${dirname} && echo "mkdir ${dirname}"; else echo ${dirname} exist; fi
	g++ -std=c++11 $^ -o ${dirname}/${n}

test:
	@./${dirname}/${n}

clean:
	rm -rf tmp