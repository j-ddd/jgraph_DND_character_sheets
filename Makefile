jgrs = $(wildcard ./*.jgr)
JGRAPH_LOCAL = ../../jgraph/jgraph
JGRAPH_HYDRA = /home/jplank/bin/LINUX-X86_64/jgraph
JGRAPH=$(JGRAPH_HYDRA)


files:
	g++ -o djdc_to_jgraph -Wall djdc_to_jgraph.cpp
	$(MAKE) -C symbols

clean:
	rm djdc_to_jgraph

junk:
	$(JGRAPH) -P $@.jgr | ps2pdf - | convert -density 300 - -quality 100 $@.jpg

testjgr:
	$(JGRAPH) -P $@.jgr | ps2pdf - | convert -density 300 - -quality 100 $@.jpg

echo:
	echo $(jgrs)
	echo $@
