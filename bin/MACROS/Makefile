CPPFLAGS=`root-config --cflags` -I/usr/local/root/include

LDFLAGS=`root-config --libs` -lMinuit


#all: plotter.o results.o left_right.o fit_opt.o sens.o draw.o fitFunc.o TH3Fit.o
#all: plotter.o fitFunc.o TH3Fit.o

all: plotter.o likelihoodFunc.o weightExtractor.o minexam.o myMinexam.o weightFiller.o likeliDraw.o example.o readParams.o tChannel.o extern.o angleCalculator.o Rotation.o finalResults.o recoFinalResults.o plotInput.o testFuncSlice.o testFunc.o handyTool.o recoResults.o compareResults.o

#	g++ $(LDFLAGS) -o test/results plotter.o results.o

#	g++ $(LDFLAGS) -o test/left_right plotter.o left_right.o

#	g++ $(LDFLAGS) -o test/fit_opt plotter.o fit_opt.o

#	g++ $(LDFLAGS) -o test/sens plotter.o sens.o
#	g++ $(LDFLAGS) -o test/draw plotter.o draw.o

#	g++ $(LDFLAGS) -o test/TH3Fit plotter.o fitFunc.o TH3Fit.o
#	g++ $(LDFLAGS) -o test/likelihood likelihood.o

	g++ $(LDFLAGS) -o test/finalResults readParams.o finalResults.o plotter.o extern.o

	g++ $(LDFLAGS) -o test/recoFinalResults readParams.o recoFinalResults.o plotter.o

	g++ $(LDFLAGS) -o test/recoResults readParams.o recoResults.o plotter.o likelihoodFunc.o extern.o tChannel.o

	g++ $(LDFLAGS) -o test/handyTool readParams.o handyTool.o plotter.o

	g++ $(LDFLAGS) -o test/weightExtractor weightExtractor.o plotter.o tChannel.o

	g++ $(LDFLAGS) -o test/weightFiller weightFiller.o plotter.o tChannel.o

#	g++ $(LDFLAGS) -o test/likelihood_1 likelihood_1.o plotter.o likelihoodFunc.o

	g++ $(LDFLAGS) -o test/minexam minexam.o

	g++ $(LDFLAGS) -o test/myMinexam likelihoodFunc.o myMinexam.o plotter.o tChannel.o readParams.o extern.o angleCalculator.o Rotation.o

#	g++ $(LDFLAGS) -o test/epsilonCalc likelihoodFunc.o epsilonCalc.o plotter.o tChannel.o readParams.o extern.o angleCalculator.o Rotation.o

	g++ $(LDFLAGS) -o test/likeliDraw likeliDraw.o plotter.o likelihoodFunc.o readParams.o tChannel.o extern.o

	g++ $(LDFLAGS) -o test/wexample example.o

	g++ $(LDFLAGS) -o test/plotInput readParams.o plotInput.o

	g++ $(LDFLAGS) -o test/testFunc readParams.o likelihoodFunc.o testFunc.o extern.o tChannel.o

	g++ $(LDFLAGS) -o test/testFuncSlice readParams.o likelihoodFunc.o testFuncSlice.o extern.o tChannel.o

	g++ $(LDFLAGS) -o test/compareResults compareResults.o plotter.o


#	rm *.o



plotInput.o: src/plotInput.cc

	g++ $(CPPFLAGS) -c $^ -I.

Rotation.o: include/Rotation.cc

	g++ $(CPPFLAGS) -c $^ -I.

finalResults.o: src/finalResults.cc

	g++ $(CPPFLAGS) -c $^ -I.

recoFinalResults.o: src/recoFinalResults.cc

	g++ $(CPPFLAGS) -c $^ -I.

recoResults.o: src/recoResults.cc

	g++ $(CPPFLAGS) -c $^ -I/include

compareResults.o: src/compareResults.cc

	g++ $(CPPFLAGS) -c $^ -I/include

handyTool.o: src/handyTool.cc

	g++ $(CPPFLAGS) -c $^ -I.

angleCalculator.o: include/angleCalculator.cc

	g++ $(CPPFLAGS) -c $^ -I.

plotter.o: include/plotter.cc

	g++ $(CPPFLAGS) -c $^ -I.

likelihoodFunc.o: include/likelihoodFunc.cc

	g++ $(CPPFLAGS) -c $^ -I.

#results.o: src/results.cc

#	g++ $(CPPFLAGS) -c $^ -I/include

#left_right.o: src/left_right.cc

#	g++ $(CPPFLAGS) -c $^ -I/include

#fit_opt.o: src/fit_opt.cc

#	g++ $(CPPFLAGS) -c $^ -I/include

#sens.o: src/sens.cc

#	g++ $(CPPFLAGS) -c $^ -I/include

#draw.o: src/draw.cc

#	g++ $(CPPFLAGS) -c $^ -I/include

#TH3Fit.o: src/TH3Fit.cc

#	g++ $(CPPFLAGS) -c $^ -I/include

#fitFunc.o: include/fitFunc.cc

#	g++ -c $^ -I/include

weightFiller.o: src/weightFiller.cc

	g++ -c $(CPPFLAGS) $^ -I/include

weightExtractor.o: src/weightExtractor.cc

	g++ -c $(CPPFLAGS) $^ -I/include

#likelihood_1.o: src/likelihood_1.cc

#	g++ -c $(CPPFLAGS) $^ -I/include

#likelihood.o: src/likelihood.cc

#	g++ -c $(CPPFLAGS) $^ -I/include

minexam.o: src/minexam.cc

	g++ -c $(CPPFLAGS) $^ -I/include

myMinexam.o: src/myMinexam.cc

	g++ -c $(CPPFLAGS) $^ -I/include

#epsilonCalc.o: src/epsilonCalc.cc

#	g++ -c $(CPPFLAGS) $^ -I/include

likeliDraw.o: src/likeliDraw.cc

	g++ -c $(CPPFLAGS) $^ -I/include

example.o: src/example.cc

	g++ -c $(CPPFLAGS) $^

readParams.o: include/readParams.cc

	g++ -c $(CPPFLAGS) $^ -I/include

tChannel.o: include/tChannel.cc

	g++ -c $(CPPFLAGS) $^ -I/include

extern.o: include/extern.cc

	g++ -c $(CPPFLAGS) $^ -I/include

testFunc.o: src/testFunc.cc

	g++ $(CPPFLAGS) -c $^ -I/include

testFuncSlice.o: src/testFuncSlice.cc

	g++ $(CPPFLAGS) -c $^ -I/include

