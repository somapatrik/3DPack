using _3DPack;

namespace PackGUI.ViewModels
{
    internal class PlanViewModel : PrimeViewModel
    {
        private PackagerResult _selectedResult;

        public PackagerResult selectedResult { get => _selectedResult; set => SetProperty(ref _selectedResult, value); }

        public PlanViewModel(PackagerResult result) 
        {
            selectedResult = result;
        }
    }
}
