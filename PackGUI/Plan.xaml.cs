using _3DPack;
using PackGUI.ViewModels;
using System.Windows;

namespace PackGUI
{
    public partial class Plan : Window
    {
        private PlanViewModel _viewModel;

        public Plan(PackagerResult result)
        {
            InitializeComponent();
            DataContext = _viewModel = new PlanViewModel(result);
        }
    }
}
