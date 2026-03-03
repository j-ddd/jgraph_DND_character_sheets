jgrs = $(wildcard ./*.jgr)
JGRAPH = /home/jplank/bin/LINUX-X86_64/jgraph

files:
	g++ -o djdc_to_jgr -Wall djdc_to_jgr.cpp
	$(MAKE) -C symbols

clean:
	rm djdc_to_jgraph

junk:
	$(JGRAPH) -P $@.jgr | ps2pdf - | convert -density 300 - -quality 100 $@.jpg

echo:
	echo $(jgrs)
	echo $@

examples: files Drake Khabib Proxy Ghengis Jobs

Drake:
	./djdc_to_jgr < ./djdcs/Drake.djdc > ./jgrs/$@.jgr
	$(JGRAPH) -P ./jgrs/$@.jgr | ps2pdf - | convert -density 300 - -quality 100 ./characters/$@.jpg

Khabib:
	./djdc_to_jgr < ./djdcs/Khabib.djdc > ./jgrs/$@.jgr
	$(JGRAPH) -P ./jgrs/$@.jgr | ps2pdf - | convert -density 300 - -quality 100 ./characters/$@.jpg

Proxy:
	./djdc_to_jgr < ./djdcs/Proxy.djdc > ./jgrs/$@.jgr
	$(JGRAPH) -P ./jgrs/$@.jgr | ps2pdf - | convert -density 300 - -quality 100 ./characters/$@.jpg

Ghengis:
	./djdc_to_jgr < ./djdcs/Ghengis.djdc > ./jgrs/$@.jgr
	$(JGRAPH) -P ./jgrs/$@.jgr | ps2pdf - | convert -density 300 - -quality 100 ./characters/$@.jpg

Jobs:
	./djdc_to_jgr < ./djdcs/Jobs.djdc > ./jgrs/$@.jgr
	$(JGRAPH) -P ./jgrs/$@.jgr | ps2pdf - | convert -density 300 - -quality 100 ./characters/$@.jpg
