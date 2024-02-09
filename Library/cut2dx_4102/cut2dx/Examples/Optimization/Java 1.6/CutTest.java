import com.jacob.activeX.ActiveXComponent;
import com.jacob.com.ComFailException;
import com.jacob.com.ComThread;
import com.jacob.com.Dispatch;
import com.jacob.com.DispatchEvents;
import com.jacob.com.Variant;


/**
 *
 * @author Claudiu Dinca - www.actualsoft.ro
 */

/*
 * 
 * help file : http://www.optimalprograms.com/help/optimization2dx/
 * component: http://www.optimalprograms.com/
 * 
 */
public class CutTest {
    private Dispatch cutController;
    private DispatchEvents events;
    
    public CutTest() {
		ComThread.InitMTA(true);
		ActiveXComponent cut2xCom = new ActiveXComponent("optimal2dx.Optimization2DX");
		
		cutController = (Dispatch)cut2xCom.getObject();
	
                events = new DispatchEvents(cutController,
                        new CutEvents(),
                        "optimal2dx.Optimization2DX");

	}


	public void putNumberOfDemandPieces(Integer value){
            Dispatch.put(cutController, "NumberOfDemandPieces", new Variant(value));
	}

        public void  putNumberOfRepositoryPieces(Integer value){
            Dispatch.put(cutController, "NumberOfRepositoryPieces", new Variant(value));
        }
        
        public void  putBladeWidth(Integer value){
            Dispatch.put(cutController, "BladeWidth", new Variant(value));
        }

        public void  putOptimizationLevel(Integer value){
            Dispatch.put(cutController, "OptimizationLevel", new Variant(value));
        }

        public void  putRandomSeed(Integer value){
            Dispatch.put(cutController, "RandomSeed", new Variant(value));
        }

        public String getTotalNumberOfUtilizedRepositoryPieces(){
            Variant res = Dispatch.get(cutController, "TotalNumberOfUtilizedRepositoryPieces");
            return res.toString();
        }

        public void setDemandPiece(Integer index, Integer length, Integer width, Integer canRotate, Integer externalId, Integer priority){
            Dispatch.call(cutController, "setDemandPiece", new Variant(index), new Variant(length), new Variant(width),
                    new Variant(canRotate), new Variant(externalId), new Variant(priority));
        }
        
        
        public NumberOfCutsObject getNumberOfCuts(Integer SheetIndex){
        	NumberOfCutsObject numcuts = new NumberOfCutsObject();
        	
        	Dispatch.call(cutController, "NumberOfCuttings", SheetIndex, numcuts.numberOfCuts, numcuts.repositoryIndex, numcuts.repositoryExternalID);
        	
        	return numcuts;
        }

        public CutObject getCut(Integer SheetIndex, Integer CutIndex){
        	CutObject cut = new CutObject();
        	
            Variant[] args = new Variant[9];
            
            args[0] = new Variant(SheetIndex);
            args[1] = new Variant(CutIndex);
            
            for (int i = 2; i < 9; i++)
            	args[i] = new Variant(new Integer(0), true);
        	
        	Dispatch.callN(cutController, "GetCut", args);// calls the native GetCut method
        	
        	cut.topx = args[2];
        	cut.topy = args[3];
        	cut.bottomx = args[4];
        	cut.bottomy = args[5];
        	cut.thickness = args[6];
        	// the other data are not important for me right now...
        	
        	return cut;
        }

        public WasteObject getWaste(Integer SheetIndex, Integer WasteIndex){
        	WasteObject waste = new WasteObject();
        	
            Variant[] args = new Variant[8];
            
            args[0] = new Variant(SheetIndex);
            args[1] = new Variant(WasteIndex);
            
            for (int i = 2; i < 8; i++)
            	args[i] = new Variant(new Integer(0), true);
        	
        	Dispatch.callN(cutController, "GetWastePiece", args); // calls the native GetWastePiece method
        	
        	waste.topx = args[2];
        	waste.topy = args[3];
        	waste.bottomx = args[4];
        	waste.bottomy = args[5];
        	// the other data are not important for me right now...
        	
        	return waste;
        }

        public DemandPiecePlacementObject getDemandPiecePlacement(Integer SheetIndex, Integer PieceIndex){
        	DemandPiecePlacementObject piece = new DemandPiecePlacementObject();
        	
            Variant[] args = new Variant[11];
            
            args[0] = new Variant(SheetIndex);
            args[1] = new Variant(PieceIndex);
            
            for (int i = 2; i < 11; i++)
            	args[i] = new Variant(new Integer(0), true);
        	
        	Dispatch.callN(cutController, "GetUtilizedDemandPiece", args); // calls the native GetUtilizedDemandPiece
        	
        	piece.topx = args[2];
        	piece.topy = args[3];
        	piece.bottomx = args[4];
        	piece.bottomy = args[5];
        	// the other data are not important for me right now...
        	
        	return piece;
        }

        public NumberOfWastesObject getNumberOfWastes(Integer SheetIndex){
        	NumberOfWastesObject numwastes = new NumberOfWastesObject();
        	
        	Dispatch.call(cutController, "NumberOfWastePieces", SheetIndex, numwastes.numberOfWastes, numwastes.repositoryIndex, numwastes.repositoryExternalID);
        	
        	return numwastes;
        }
        

        public NumberOfPlacedPiecesObject getNumberOfPlacedPieces(Integer SheetIndex){
        	NumberOfPlacedPiecesObject numpieces = new NumberOfPlacedPiecesObject();
        	
        	Dispatch.call(cutController, "NumberOfUtilizedDemandPieces", SheetIndex, numpieces.numberOfPlacedPieces, numpieces.repositoryIndex, numpieces.repositoryExternalID);
        	
        	return numpieces;
        }
        
        public void setRepositoryPiece(Integer index, Integer length, Integer width,
        		Integer trimTop, Integer trimLeft, Integer trimBottom, Integer trimRight,
        		Integer externalId, Integer priority, Integer numbersOfHoles){
            Variant[] args = new Variant[10];
            int i=0;
            args[i++] = new Variant(index);
            args[i++] = new Variant(length); args[i++] = new Variant(width);
            args[i++] = new Variant(trimTop); args[i++] = new Variant(trimLeft); args[i++] = new Variant(trimBottom); args[i++] =  new Variant(trimRight);
            args[i++] = new Variant(externalId); args[i++] = new Variant(priority); 
            args[i++] = new Variant(numbersOfHoles);

            Dispatch.callN(cutController, "SetRepositoryPiece", args);
        }

        public void startGuillotine(){
             Dispatch.call(cutController, "StartGuillotine");
        }



        public class CutEvents {
		public void OnFinish (Variant[] args) {

                    //Dispatch ctrl = (Dispatch)args[0].getDispatch();
			Variant totalNumberOfUtilizedRepositoryPieces = Dispatch.get(cutController, "TotalNumberOfUtilizedRepositoryPieces");

		    System.out.println("Number of sheets: " + totalNumberOfUtilizedRepositoryPieces.getInt());
		    System.out.println("---------------------------------------");
            // now for each sheet
		    for (int SheetIndex = 0; SheetIndex < totalNumberOfUtilizedRepositoryPieces.getInt(); SheetIndex++){
		      System.out.println("SHEET: #" + SheetIndex);
              // the cuts 
              NumberOfCutsObject numcuts =  getNumberOfCuts(SheetIndex);
              System.out.println("Number of cuts: " + numcuts.getNumberOfCuts());
              if (numcuts.getNumberOfCuts() > 0){
            	  System.out.println("The cuts are (top_x,top_y)-(bottom_x,bottom_y):");
            	  for (int j = 0; j < numcuts.getNumberOfCuts(); j++){
            		  CutObject cut = getCut(SheetIndex, j);
            		  System.out.println("(" + cut.get_topx() + "," + cut.get_topy() + ")-(" + cut.get_bottomx() + "," + cut.get_bottomy()+")");
            	  }
              }
              // piece position
              NumberOfPlacedPiecesObject numpieces =  getNumberOfPlacedPieces(SheetIndex);
              System.out.println("Number of utilized demand pieces: " + numpieces.getNumberOfPlacedPieces());
              System.out.println("The piece positions are (top_x,top_y)-(bottom_x,bottom_y):");
              for (int j = 0; j < numpieces.getNumberOfPlacedPieces(); j++){
            	  DemandPiecePlacementObject piece = getDemandPiecePlacement(SheetIndex, j);
           		  System.out.println("(" + piece.get_topx() + "," + piece.get_topy() + ")-(" + piece.get_bottomx() + "," + piece.get_bottomy()+")");
              }

              // wastes
              NumberOfWastesObject numwastes =  getNumberOfWastes(SheetIndex);
              System.out.println("Number of wastes: " + numwastes.getNumberOfWastes());
              if (numwastes.getNumberOfWastes() > 0){
            	  System.out.println("The wastes are (top_x,top_y)-(bottom_x,bottom_y):");
            	  for (int j = 0; j < numwastes.getNumberOfWastes(); j++){
            		  WasteObject waste = getWaste(SheetIndex, j);
            		  System.out.println("(" + waste.get_topx() + "," + waste.get_topy() + ")-(" + waste.get_bottomx() + "," + waste.get_bottomy()+")");
            	  }
              }

              System.out.println("--------------------------------");
		    }

		}

                public void OnProgress(Variant[] args) {
			System.out.println("..progres");
		}

	}
        
        
       public class NumberOfCutsObject { 
    	   	public Variant numberOfCuts = new Variant(new Integer(0), true);  
    	   	public Variant repositoryIndex = new Variant(new Integer(0), true); 
    	   	public Variant repositoryExternalID = new Variant(new Integer(0), true);
    	   	    	   	
    	   	public int getNumberOfCuts(){
    	   		return numberOfCuts.getIntRef();
    	   	}    	   
       }
       
       public class NumberOfWastesObject { 
   	   	 public Variant numberOfWastes = new Variant(new Integer(0), true);  
   	   	 public Variant repositoryIndex = new Variant(new Integer(0), true); 
   	   	 public Variant repositoryExternalID = new Variant(new Integer(0), true);
   	   	    	   	
   	   	 public int getNumberOfWastes(){
   	   		return numberOfWastes.getIntRef();
   	   	 }    	   
       }

       public class NumberOfPlacedPiecesObject { 
     	   	 public Variant numberOfPlacedPieces = new Variant(new Integer(0), true);  
     	   	 public Variant repositoryIndex = new Variant(new Integer(0), true); 
     	   	 public Variant repositoryExternalID = new Variant(new Integer(0), true);
     	   	    	   	
     	   	 public int getNumberOfPlacedPieces(){
     	   		return numberOfPlacedPieces.getIntRef();
     	   	 }    	   
         }

       public class CutObject {
   	   	public Variant topx = new Variant(new Integer(0), true);  
   	   	public Variant topy = new Variant(new Integer(0), true); 
   	   	public Variant bottomx = new Variant(new Integer(0), true);
   	   	public Variant bottomy = new Variant(new Integer(0), true);
   	   	public Variant thickness = new Variant(new Integer(0), true);
	   	public Variant repositoryIndex = new Variant(new Integer(0), true); 
	   	public Variant repositoryExternalID = new Variant(new Integer(0), true);
   	   	    	   	
   	   	public int get_topx(){
   	   		return topx.getIntRef();
   	   	}    	   
   	   	public int get_topy(){
   	   		return topy.getIntRef();
   	   	}    	   
   	   	public int get_bottomx(){
   	   		return bottomx.getIntRef();
   	   	}    	   
   	   	public int get_bottomy(){
   	   		return bottomy.getIntRef();
   	   	}    	   
   	   	public int get_thickness(){
   	   		return thickness.getIntRef();
   	   	}    	   
      }

       public class WasteObject {
      	   	public Variant topx = new Variant(new Integer(0), true);  
      	   	public Variant topy = new Variant(new Integer(0), true); 
      	   	public Variant bottomx = new Variant(new Integer(0), true);
      	   	public Variant bottomy = new Variant(new Integer(0), true);
     	   	public Variant repositoryIndex = new Variant(new Integer(0), true); 
     	   	public Variant repositoryExternalID = new Variant(new Integer(0), true);
      	   	    	   	
      	   	public int get_topx(){
      	   		return topx.getIntRef();
      	   	}    	   
      	   	public int get_topy(){
      	   		return topy.getIntRef();
      	   	}    	   
      	   	public int get_bottomx(){
      	   		return bottomx.getIntRef();
      	   	}    	   
      	   	public int get_bottomy(){
      	   		return bottomy.getIntRef();
      	   	}    	   
         }

       public class DemandPiecePlacementObject {
     	   	public Variant topx = new Variant(new Integer(0), true);  
      	   	public Variant topy = new Variant(new Integer(0), true); 
      	   	public Variant bottomx = new Variant(new Integer(0), true);
      	   	public Variant bottomy = new Variant(new Integer(0), true);
      	    public Variant rotated = new Variant(new Integer(0), true);
     	   	public Variant repositoryIndex = new Variant(new Integer(0), true); 
     	    public Variant demandIndex = new Variant(new Integer(0), true);
     	   	public Variant repositoryExternalID = new Variant(new Integer(0), true);
     	    public Variant demandExternalID = new Variant(new Integer(0), true);
   	   	
   	   	
      	   	public int get_topx(){
      	   		return topx.getIntRef();
      	   	}    	   
      	   	public int get_topy(){
      	   		return topy.getIntRef();
      	   	}    	   
      	   	public int get_bottomx(){
      	   		return bottomx.getIntRef();
      	   	}    	   
      	   	public int get_bottomy(){
      	   		return bottomy.getIntRef();
      	   	}    	   
      }       

        private void runTest(){
            putNumberOfDemandPieces(14);
            setDemandPiece(0, 60, 40, 1, 0, 0);
            
             setDemandPiece(1, 60, 40, 1, 1, 0);
             setDemandPiece(2, 48, 40, 1, 2, 0);
             setDemandPiece(3, 60, 53, 1, 3, 0);
             setDemandPiece(4, 45, 45, 1, 4, 0);
             setDemandPiece(5, 50, 80, 1, 5, 0);
             setDemandPiece(6, 45, 75, 1, 6, 0);
             setDemandPiece(7, 100, 100, 1, 7, 0);
             setDemandPiece(8, 100, 100, 1, 8, 0);
             setDemandPiece(9, 90, 90, 1, 9, 0);
             
             setDemandPiece(10, 90, 90, 1, 10, 0);
             setDemandPiece(11, 90, 90, 1, 11, 0);
             setDemandPiece(12, 110, 110, 1, 12, 0);
             setDemandPiece(13, 110, 110, 1, 13, 0);

             putNumberOfRepositoryPieces(3);

              setRepositoryPiece(0, 300, 200, 0, 0, 0, 0, 0, 0, 0);
              setRepositoryPiece(1, 200, 200, 0, 0, 0, 0, 1, 0, 0);
              setRepositoryPiece(2, 300, 250, 0, 0, 0, 0, 2, 0, 0);

              putBladeWidth(0);
              putOptimizationLevel(50);
              putRandomSeed(1);

              startGuillotine();

        }


	public static void main(String args[]) throws Exception {
            try{
		CutTest test = new CutTest();

                test.runTest();
            } catch(ComFailException e){
                System.out.println("ups!");
                e.printStackTrace();
            }finally {
                ComThread.Release();
            }
                

	}

} 