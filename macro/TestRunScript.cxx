#include "../source/cluster/ClusterKAA.cpp"

int TestRunScript()
{
  string dir_data = "/eos/nica/mpd/sim/data/exp/dst-BiBi-09.2GeV-mp05-21-500ev/BiBi/09.2GeV-mb/UrQMD/BiBi-09.2GeV-mp05-21-500ev/";
  string data_file = dir_data + "urqmd-BiBi-09.2GeV-mb-eos0-500-11801.reco.root";

  TChain* Read_Chain = new TChain("mpdsim");
  Read_Chain -> Add(data_file.c_str());
  
  TObjArray* Clusters = nullptr;
  TClonesArray* MCStack = nullptr;
  TClonesArray* KalmanStack = nullptr;
  MpdEvent* Event = nullptr;
  MpdMCEventHeader* MCEventHeader = nullptr;
  Read_Chain -> SetBranchAddress("MCTrack", &MCStack);
  Read_Chain -> SetBranchAddress("EmcCluster", &Clusters);
  Read_Chain -> SetBranchAddress("MPDEvent.", &Event);
  Read_Chain -> SetBranchAddress("MCEventHeader.", &MCEventHeader);
  Read_Chain -> SetBranchAddress("TpcKalmanTrack", &KalmanStack);

  
  TH1D* h_dz_all_test = new TH1D("h_dz_all_test","h_dz_all_test", 400, -200, 200);

  for (int i = 0; i < Read_Chain -> GetEntries(); i++)
    {
      std::cout << i << std::endl;
      Read_Chain -> GetEntry(i);
      
      for (int j = 0; j < Clusters -> GetEntries(); j++)
	{

	  ClusterKAA* my_clu = new ClusterKAA( (MpdEmcClusterKI*)Clusters -> At(j));
	  h_dz_all_test -> Fill(my_clu -> GetDZ());
	}

    }
  
  TFile* f_out = new TFile("test.root", "recreate");
  h_dz_all_test -> Write();


  return 0;
}
