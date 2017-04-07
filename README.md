# miniball-analysis-code
Analysis code for MINIBALL experiments at ISOLDE

Code to take med data files and convert them to run and subsequently analyse

### Basic process for analysis

To generate inital root file
```
cd MedToRoot
make

./MBEventBuilder -mf data_file.med - sf setting_file.dat -so
```
data_file_Scaler.root & data_file_Source.root will be created.

Scaler file is needed during the experiment and Source file is needed for analysis.

```
./BuildEventTree -i data_file_Source.root -o Output.root -c calibration_file.dat
```

Generated file can now be used as input to final analysis code

```
cd ../TreeAna
make
./g_clx -i Output.root -o Final_Output.root
```


