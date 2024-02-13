using _3DPack;
using PackGUI.Models;
using System.Collections.ObjectModel;

namespace PackGUI.ViewModels
{
    internal class PlanViewModel : PrimeViewModel
    {
        private ObservableCollection<TruckDeckModel> _decks;

        public ObservableCollection<TruckDeckModel> Decks { get => _decks; set => SetProperty(ref _decks, value); }


        public PlanViewModel(List<TruckDeckModel> decks)
        {
            Decks = new ObservableCollection<TruckDeckModel>();
            decks.ForEach(Decks.Add);
        }
    }
}
