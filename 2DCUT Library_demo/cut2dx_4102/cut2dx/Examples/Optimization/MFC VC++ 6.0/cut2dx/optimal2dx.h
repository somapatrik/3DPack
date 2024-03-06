/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun May 03 12:17:21 2009
 */
/* Compiler settings for C:\tmp\cut2dx\optimal2dx.IDL:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __optimal2dx_h__
#define __optimal2dx_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IOptimization2DX_FWD_DEFINED__
#define __IOptimization2DX_FWD_DEFINED__
typedef interface IOptimization2DX IOptimization2DX;
#endif 	/* __IOptimization2DX_FWD_DEFINED__ */


#ifndef __IOptimization2DXEvents_FWD_DEFINED__
#define __IOptimization2DXEvents_FWD_DEFINED__
typedef interface IOptimization2DXEvents IOptimization2DXEvents;
#endif 	/* __IOptimization2DXEvents_FWD_DEFINED__ */


#ifndef __Optimization2DX_FWD_DEFINED__
#define __Optimization2DX_FWD_DEFINED__

#ifdef __cplusplus
typedef class Optimization2DX Optimization2DX;
#else
typedef struct Optimization2DX Optimization2DX;
#endif /* __cplusplus */

#endif 	/* __Optimization2DX_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __optimal2dx_LIBRARY_DEFINED__
#define __optimal2dx_LIBRARY_DEFINED__

/* library optimal2dx */
/* [helpstring][version][uuid] */ 




EXTERN_C const IID LIBID_optimal2dx;

#ifndef __IOptimization2DX_INTERFACE_DEFINED__
#define __IOptimization2DX_INTERFACE_DEFINED__

/* interface IOptimization2DX */
/* [object][oleautomation][dual][helpstring][version][uuid] */ 


EXTERN_C const IID IID_IOptimization2DX;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E7C266EF-2634-42F9-A1AC-96C7DB050DB2")
    IOptimization2DX : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_OptimizationLevel( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_OptimizationLevel( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_BladeWidth( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_BladeWidth( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NumberOfDemandPieces( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_NumberOfDemandPieces( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_RandomSeed( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_RandomSeed( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ComputerID( 
            /* [retval][out] */ BSTR __RPC_FAR *Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_IsRegistered( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NumberOfRepositoryPieces( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_NumberOfRepositoryPieces( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CallerName( 
            /* [retval][out] */ BSTR __RPC_FAR *Value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartGuillotine( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartNested( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartMultiStages( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetDemandPiece( 
            /* [in] */ long Index,
            /* [in] */ long Length,
            /* [in] */ long Width,
            /* [in] */ long CanRotate,
            /* [in] */ long ExternalID,
            /* [in] */ long Priority) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetDemandPiece( 
            /* [in] */ long Index,
            /* [out] */ long __RPC_FAR *Length,
            /* [out] */ long __RPC_FAR *Width,
            /* [out] */ long __RPC_FAR *CanRotate,
            /* [out] */ long __RPC_FAR *ExternalID,
            /* [out] */ long __RPC_FAR *Priority) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetRepositoryPiece( 
            /* [in] */ long Index,
            /* [in] */ long Length,
            /* [in] */ long Width,
            /* [in] */ long TrimTop,
            /* [in] */ long TrimLeft,
            /* [in] */ long TrimBottom,
            /* [in] */ long TrimRight,
            /* [in] */ long ExternalID,
            /* [in] */ long Priority,
            /* [in] */ long NumberOfHoles) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRepositoryPiece( 
            /* [in] */ long Index,
            /* [out] */ long __RPC_FAR *Length,
            /* [out] */ long __RPC_FAR *Width,
            /* [out] */ long __RPC_FAR *TrimTop,
            /* [out] */ long __RPC_FAR *TrimLeft,
            /* [out] */ long __RPC_FAR *TrimBottom,
            /* [out] */ long __RPC_FAR *TrimRight,
            /* [out] */ long __RPC_FAR *ExternalID,
            /* [out] */ long __RPC_FAR *Priority,
            /* [out] */ long __RPC_FAR *NumberOfHoles) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Version( 
            /* [retval][out] */ BSTR __RPC_FAR *Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Expired( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TotalNumberOfUtilizedDemandPieces( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RegisterOptimization2DX( 
            /* [in] */ BSTR UserName,
            /* [in] */ BSTR SerialNumber) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TotalNumberOfUtilizedRepositoryPieces( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_WhichStartMethodStarted( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MinimalWidthBreakage( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_MinimalWidthBreakage( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MaximalCutLength( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_MaximalCutLength( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_FirstDirectionMultiStages( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_FirstDirectionMultiStages( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ShowWarnings( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ShowWarnings( 
            /* [in] */ long Value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NumberOfCuttings( 
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *NumberOfCuts,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NumberOfUtilizedDemandPieces( 
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *NumberOfUtilizedPieces,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE NumberOfWastePieces( 
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *NumberOfWastePieces,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SurfaceCovered( 
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *SurfaceCovered,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCut( 
            /* [in] */ long SheetIndex,
            /* [in] */ long CutIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *CutThickness,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetUtilizedDemandPiece( 
            /* [in] */ long SheetIndex,
            /* [in] */ long PieceIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *Rotated,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *DemandIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID,
            /* [out] */ long __RPC_FAR *DemandExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetWastePiece( 
            /* [in] */ long SheetIndex,
            /* [in] */ long WasteIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DemandPieceUtilized( 
            /* [in] */ long DemandIndex,
            /* [out] */ long __RPC_FAR *SheetIndex,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *DemandExternalID,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE RepositoryPieceUtilized( 
            /* [in] */ long Index,
            /* [out] */ long __RPC_FAR *Utilized,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetUtilizedRepositoryPiece( 
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CutAllStripsFirst( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_CutAllStripsFirst( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_OnlyPiecesOfTheSameHeightInAStrip( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_OnlyPiecesOfTheSameHeightInAStrip( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_HeightTolerance( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_HeightTolerance( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ManualArrangeNumberOfCuts( 
            /* [in] */ long rhs) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ManualArrangeNumberOfPieces( 
            /* [in] */ long rhs) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ManualArrangeNumberOfWastes( 
            /* [in] */ long rhs) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeSetCut( 
            /* [in] */ long Index,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long CutThickness) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeSetPiecePosition( 
            /* [in] */ long Index,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long Rotated,
            /* [in] */ long ExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeSetWasteRectangle( 
            /* [in] */ long Index,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeGuillotineAddPiece( 
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long Rotated,
            /* [in] */ long CutType,
            /* [in] */ long ExternalID,
            /* [out] */ long __RPC_FAR *IndexWasteRemoved,
            /* [out] */ long __RPC_FAR *IndexWasteInserted1,
            /* [out] */ long __RPC_FAR *IndexWasteInserted2,
            /* [out] */ long __RPC_FAR *IndexCutInserted1,
            /* [out] */ long __RPC_FAR *IndexCutInserted2,
            /* [out] */ long __RPC_FAR *AllowAdd) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeIsValidPositionForAPiece( 
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long CutType,
            /* [out] */ long __RPC_FAR *AllowCut) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeNStagesAddPiece( 
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long Rotated,
            /* [in] */ long ExternalID,
            /* [out] */ long __RPC_FAR *IndexWasteRemoved,
            /* [out] */ long __RPC_FAR *IndexWasteInserted1,
            /* [out] */ long __RPC_FAR *IndexWasteInserted2,
            /* [out] */ long __RPC_FAR *IndexCutInserted1,
            /* [out] */ long __RPC_FAR *IndexCutInserted2,
            /* [out] */ long __RPC_FAR *AllowAdd) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeGuillotineRemovePiece( 
            /* [in] */ long IndexOfPiece) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeGuillotineMovePiece( 
            /* [in] */ long Index,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long Rotated,
            /* [in] */ long CutType,
            /* [out] */ long __RPC_FAR *AllowMove) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeAddCut( 
            /* [in] */ long X,
            /* [in] */ long Y,
            /* [in] */ long CutType,
            /* [in] */ long CutThickness,
            /* [out] */ long __RPC_FAR *AllowCut,
            /* [out] */ long __RPC_FAR *IndexOfAddedCut,
            /* [out] */ long __RPC_FAR *IndexOfRemovedWaste,
            /* [out] */ long __RPC_FAR *IndexOfAddedWaste1,
            /* [out] */ long __RPC_FAR *IndexOfAddedWaste2) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeGlueCuts( 
            /* [in] */ long IndexCut1,
            /* [in] */ long IndexCut2,
            /* [in] */ long IndexCut3,
            /* [out] */ long __RPC_FAR *IndexNewCut1,
            /* [out] */ long __RPC_FAR *IndexNewCut2,
            /* [out] */ long __RPC_FAR *IndexNewCut3,
            /* [out] */ long __RPC_FAR *AllowJoin) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeRemoveCut( 
            /* [in] */ long IndexCut,
            /* [out] */ long __RPC_FAR *IndexRemovedWaste1,
            /* [out] */ long __RPC_FAR *IndexRemovedWaste2,
            /* [out] */ long __RPC_FAR *IndexInsertedWaste) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeSwitchCut( 
            /* [in] */ long IndexCut,
            /* [out] */ long __RPC_FAR *JoinPerformed) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeIsValidSwitchCut( 
            /* [in] */ long IndexCut,
            /* [out] */ long __RPC_FAR *AllowSwitch) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeIsValidRemoveCut( 
            /* [in] */ long IndexCut,
            /* [out] */ long __RPC_FAR *AllowRemove) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeSwitchCutOrientation( 
            /* [in] */ long IndexCut,
            /* [in] */ long X,
            /* [in] */ long Y,
            /* [out] */ long __RPC_FAR *AllowSwitchOrientation) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeIsValidSwitchCutOrientation( 
            /* [in] */ long IndexCut,
            /* [in] */ long X,
            /* [in] */ long Y,
            /* [out] */ long __RPC_FAR *AllowSwitchOrientation) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeIsValidAddCut( 
            /* [in] */ long X,
            /* [in] */ long Y,
            /* [in] */ long CutType,
            /* [in] */ long CutThickness,
            /* [out] */ long __RPC_FAR *AllowAddCut) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ManualArrangeOptimizationType( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ManualArrangeOptimizationType( 
            /* [in] */ long Value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ManualArrangeGuillotineIsValidPositionForAPiece( 
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long CutType,
            /* [out] */ long __RPC_FAR *AllowCut) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_TrimType( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_TrimType( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_NumberOfStages( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_NumberOfStages( 
            /* [in] */ long Value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SaveToFile( 
            /* [in] */ BSTR FileName,
            /* [in] */ long SaveInputData,
            /* [in] */ long SaveParameters,
            /* [in] */ long SaveResults) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LoadFromFile( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetRepositoryHole( 
            /* [in] */ long RepositoryIndex,
            /* [in] */ long HoleIndex,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long ExternalIDofHole) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetRepositoryHole( 
            /* [in] */ long RepositoryIndex,
            /* [in] */ long HoleIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *ExternalIDofHole) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BasicCNC( 
            /* [in] */ long SheetIndex,
            /* [out] */ BSTR __RPC_FAR *CNC,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Identification( 
            /* [in] */ long rhs) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MinimalUsefulSize( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_MinimalUsefulSize( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MinStripSize( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_MinStripSize( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MaxStripSize( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_MaxStripSize( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_AllowPrecuts( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_AllowPrecuts( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_PrecutDirection( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_PrecutDirection( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_GenerateBasicCNC( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_GenerateBasicCNC( 
            /* [in] */ long Value) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE WasteSurface( 
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *Surface,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GarbageWaste( 
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *Surface,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CutSurface( 
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *Surface,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE CutLength( 
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *Length,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE StartNestingRolls( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BasicCNCNumberOfCuts( 
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *NumberOfCuts,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE BasicCNCGetCut( 
            /* [in] */ long SheetIndex,
            /* [in] */ long CutIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *CutThickness,
            /* [out] */ long __RPC_FAR *Level,
            /* [out] */ long __RPC_FAR *Type,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetCutMultiStages( 
            /* [in] */ long SheetIndex,
            /* [in] */ long CutIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *CutThickness,
            /* [out] */ long __RPC_FAR *Level,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_MaximalGarbageSize( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_MaximalGarbageSize( 
            /* [in] */ long Value) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_SinglePieceStrips( 
            /* [retval][out] */ long __RPC_FAR *Value) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_SinglePieceStrips( 
            /* [in] */ long Value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOptimization2DXVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOptimization2DX __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOptimization2DX __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOptimization2DX __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OptimizationLevel )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OptimizationLevel )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BladeWidth )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BladeWidth )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumberOfDemandPieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NumberOfDemandPieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RandomSeed )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RandomSeed )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ComputerID )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IsRegistered )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumberOfRepositoryPieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NumberOfRepositoryPieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CallerName )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartGuillotine )( 
            IOptimization2DX __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartNested )( 
            IOptimization2DX __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartMultiStages )( 
            IOptimization2DX __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDemandPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [in] */ long Length,
            /* [in] */ long Width,
            /* [in] */ long CanRotate,
            /* [in] */ long ExternalID,
            /* [in] */ long Priority);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDemandPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [out] */ long __RPC_FAR *Length,
            /* [out] */ long __RPC_FAR *Width,
            /* [out] */ long __RPC_FAR *CanRotate,
            /* [out] */ long __RPC_FAR *ExternalID,
            /* [out] */ long __RPC_FAR *Priority);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Stop )( 
            IOptimization2DX __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRepositoryPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [in] */ long Length,
            /* [in] */ long Width,
            /* [in] */ long TrimTop,
            /* [in] */ long TrimLeft,
            /* [in] */ long TrimBottom,
            /* [in] */ long TrimRight,
            /* [in] */ long ExternalID,
            /* [in] */ long Priority,
            /* [in] */ long NumberOfHoles);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRepositoryPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [out] */ long __RPC_FAR *Length,
            /* [out] */ long __RPC_FAR *Width,
            /* [out] */ long __RPC_FAR *TrimTop,
            /* [out] */ long __RPC_FAR *TrimLeft,
            /* [out] */ long __RPC_FAR *TrimBottom,
            /* [out] */ long __RPC_FAR *TrimRight,
            /* [out] */ long __RPC_FAR *ExternalID,
            /* [out] */ long __RPC_FAR *Priority,
            /* [out] */ long __RPC_FAR *NumberOfHoles);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Version )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Expired )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TotalNumberOfUtilizedDemandPieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RegisterOptimization2DX )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ BSTR UserName,
            /* [in] */ BSTR SerialNumber);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TotalNumberOfUtilizedRepositoryPieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_WhichStartMethodStarted )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MinimalWidthBreakage )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MinimalWidthBreakage )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MaximalCutLength )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MaximalCutLength )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_FirstDirectionMultiStages )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_FirstDirectionMultiStages )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShowWarnings )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShowWarnings )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NumberOfCuttings )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *NumberOfCuts,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NumberOfUtilizedDemandPieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *NumberOfUtilizedPieces,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *NumberOfWastePieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *NumberOfWastePieces,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SurfaceCovered )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *SurfaceCovered,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [in] */ long CutIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *CutThickness,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUtilizedDemandPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [in] */ long PieceIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *Rotated,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *DemandIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID,
            /* [out] */ long __RPC_FAR *DemandExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetWastePiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [in] */ long WasteIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DemandPieceUtilized )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long DemandIndex,
            /* [out] */ long __RPC_FAR *SheetIndex,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *DemandExternalID,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RepositoryPieceUtilized )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [out] */ long __RPC_FAR *Utilized,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetUtilizedRepositoryPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CutAllStripsFirst )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_CutAllStripsFirst )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_OnlyPiecesOfTheSameHeightInAStrip )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_OnlyPiecesOfTheSameHeightInAStrip )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_HeightTolerance )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_HeightTolerance )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ManualArrangeNumberOfCuts )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long rhs);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ManualArrangeNumberOfPieces )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long rhs);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ManualArrangeNumberOfWastes )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long rhs);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeSetCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long CutThickness);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeSetPiecePosition )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long Rotated,
            /* [in] */ long ExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeSetWasteRectangle )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeGuillotineAddPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long Rotated,
            /* [in] */ long CutType,
            /* [in] */ long ExternalID,
            /* [out] */ long __RPC_FAR *IndexWasteRemoved,
            /* [out] */ long __RPC_FAR *IndexWasteInserted1,
            /* [out] */ long __RPC_FAR *IndexWasteInserted2,
            /* [out] */ long __RPC_FAR *IndexCutInserted1,
            /* [out] */ long __RPC_FAR *IndexCutInserted2,
            /* [out] */ long __RPC_FAR *AllowAdd);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeIsValidPositionForAPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long CutType,
            /* [out] */ long __RPC_FAR *AllowCut);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeNStagesAddPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long Rotated,
            /* [in] */ long ExternalID,
            /* [out] */ long __RPC_FAR *IndexWasteRemoved,
            /* [out] */ long __RPC_FAR *IndexWasteInserted1,
            /* [out] */ long __RPC_FAR *IndexWasteInserted2,
            /* [out] */ long __RPC_FAR *IndexCutInserted1,
            /* [out] */ long __RPC_FAR *IndexCutInserted2,
            /* [out] */ long __RPC_FAR *AllowAdd);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeGuillotineRemovePiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long IndexOfPiece);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeGuillotineMovePiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Index,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long Rotated,
            /* [in] */ long CutType,
            /* [out] */ long __RPC_FAR *AllowMove);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeAddCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long X,
            /* [in] */ long Y,
            /* [in] */ long CutType,
            /* [in] */ long CutThickness,
            /* [out] */ long __RPC_FAR *AllowCut,
            /* [out] */ long __RPC_FAR *IndexOfAddedCut,
            /* [out] */ long __RPC_FAR *IndexOfRemovedWaste,
            /* [out] */ long __RPC_FAR *IndexOfAddedWaste1,
            /* [out] */ long __RPC_FAR *IndexOfAddedWaste2);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeGlueCuts )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long IndexCut1,
            /* [in] */ long IndexCut2,
            /* [in] */ long IndexCut3,
            /* [out] */ long __RPC_FAR *IndexNewCut1,
            /* [out] */ long __RPC_FAR *IndexNewCut2,
            /* [out] */ long __RPC_FAR *IndexNewCut3,
            /* [out] */ long __RPC_FAR *AllowJoin);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeRemoveCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long IndexCut,
            /* [out] */ long __RPC_FAR *IndexRemovedWaste1,
            /* [out] */ long __RPC_FAR *IndexRemovedWaste2,
            /* [out] */ long __RPC_FAR *IndexInsertedWaste);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeSwitchCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long IndexCut,
            /* [out] */ long __RPC_FAR *JoinPerformed);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeIsValidSwitchCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long IndexCut,
            /* [out] */ long __RPC_FAR *AllowSwitch);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeIsValidRemoveCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long IndexCut,
            /* [out] */ long __RPC_FAR *AllowRemove);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeSwitchCutOrientation )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long IndexCut,
            /* [in] */ long X,
            /* [in] */ long Y,
            /* [out] */ long __RPC_FAR *AllowSwitchOrientation);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeIsValidSwitchCutOrientation )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long IndexCut,
            /* [in] */ long X,
            /* [in] */ long Y,
            /* [out] */ long __RPC_FAR *AllowSwitchOrientation);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeIsValidAddCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long X,
            /* [in] */ long Y,
            /* [in] */ long CutType,
            /* [in] */ long CutThickness,
            /* [out] */ long __RPC_FAR *AllowAddCut);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ManualArrangeOptimizationType )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ManualArrangeOptimizationType )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ManualArrangeGuillotineIsValidPositionForAPiece )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long CutType,
            /* [out] */ long __RPC_FAR *AllowCut);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_TrimType )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_TrimType )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_NumberOfStages )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_NumberOfStages )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SaveToFile )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ BSTR FileName,
            /* [in] */ long SaveInputData,
            /* [in] */ long SaveParameters,
            /* [in] */ long SaveResults);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LoadFromFile )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRepositoryHole )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long RepositoryIndex,
            /* [in] */ long HoleIndex,
            /* [in] */ long TopX,
            /* [in] */ long TopY,
            /* [in] */ long BottomX,
            /* [in] */ long BottomY,
            /* [in] */ long ExternalIDofHole);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRepositoryHole )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long RepositoryIndex,
            /* [in] */ long HoleIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *ExternalIDofHole);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BasicCNC )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ BSTR __RPC_FAR *CNC,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Identification )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long rhs);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MinimalUsefulSize )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MinimalUsefulSize )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MinStripSize )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MinStripSize )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MaxStripSize )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MaxStripSize )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_AllowPrecuts )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_AllowPrecuts )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_PrecutDirection )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_PrecutDirection )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GenerateBasicCNC )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GenerateBasicCNC )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *WasteSurface )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *Surface,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GarbageWaste )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *Surface,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CutSurface )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *Surface,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CutLength )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ double __RPC_FAR *Length,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *StartNestingRolls )( 
            IOptimization2DX __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BasicCNCNumberOfCuts )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [out] */ long __RPC_FAR *NumberOfCuts,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BasicCNCGetCut )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [in] */ long CutIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *CutThickness,
            /* [out] */ long __RPC_FAR *Level,
            /* [out] */ long __RPC_FAR *Type,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCutMultiStages )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long SheetIndex,
            /* [in] */ long CutIndex,
            /* [out] */ long __RPC_FAR *TopX,
            /* [out] */ long __RPC_FAR *TopY,
            /* [out] */ long __RPC_FAR *BottomX,
            /* [out] */ long __RPC_FAR *BottomY,
            /* [out] */ long __RPC_FAR *CutThickness,
            /* [out] */ long __RPC_FAR *Level,
            /* [out] */ long __RPC_FAR *RepositoryIndex,
            /* [out] */ long __RPC_FAR *RepositoryExternalID);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MaximalGarbageSize )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MaximalGarbageSize )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_SinglePieceStrips )( 
            IOptimization2DX __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Value);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_SinglePieceStrips )( 
            IOptimization2DX __RPC_FAR * This,
            /* [in] */ long Value);
        
        END_INTERFACE
    } IOptimization2DXVtbl;

    interface IOptimization2DX
    {
        CONST_VTBL struct IOptimization2DXVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOptimization2DX_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOptimization2DX_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOptimization2DX_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOptimization2DX_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOptimization2DX_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOptimization2DX_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOptimization2DX_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOptimization2DX_get_OptimizationLevel(This,Value)	\
    (This)->lpVtbl -> get_OptimizationLevel(This,Value)

#define IOptimization2DX_put_OptimizationLevel(This,Value)	\
    (This)->lpVtbl -> put_OptimizationLevel(This,Value)

#define IOptimization2DX_get_BladeWidth(This,Value)	\
    (This)->lpVtbl -> get_BladeWidth(This,Value)

#define IOptimization2DX_put_BladeWidth(This,Value)	\
    (This)->lpVtbl -> put_BladeWidth(This,Value)

#define IOptimization2DX_get_NumberOfDemandPieces(This,Value)	\
    (This)->lpVtbl -> get_NumberOfDemandPieces(This,Value)

#define IOptimization2DX_put_NumberOfDemandPieces(This,Value)	\
    (This)->lpVtbl -> put_NumberOfDemandPieces(This,Value)

#define IOptimization2DX_get_RandomSeed(This,Value)	\
    (This)->lpVtbl -> get_RandomSeed(This,Value)

#define IOptimization2DX_put_RandomSeed(This,Value)	\
    (This)->lpVtbl -> put_RandomSeed(This,Value)

#define IOptimization2DX_get_ComputerID(This,Value)	\
    (This)->lpVtbl -> get_ComputerID(This,Value)

#define IOptimization2DX_get_IsRegistered(This,Value)	\
    (This)->lpVtbl -> get_IsRegistered(This,Value)

#define IOptimization2DX_get_NumberOfRepositoryPieces(This,Value)	\
    (This)->lpVtbl -> get_NumberOfRepositoryPieces(This,Value)

#define IOptimization2DX_put_NumberOfRepositoryPieces(This,Value)	\
    (This)->lpVtbl -> put_NumberOfRepositoryPieces(This,Value)

#define IOptimization2DX_get_CallerName(This,Value)	\
    (This)->lpVtbl -> get_CallerName(This,Value)

#define IOptimization2DX_StartGuillotine(This)	\
    (This)->lpVtbl -> StartGuillotine(This)

#define IOptimization2DX_StartNested(This)	\
    (This)->lpVtbl -> StartNested(This)

#define IOptimization2DX_StartMultiStages(This)	\
    (This)->lpVtbl -> StartMultiStages(This)

#define IOptimization2DX_SetDemandPiece(This,Index,Length,Width,CanRotate,ExternalID,Priority)	\
    (This)->lpVtbl -> SetDemandPiece(This,Index,Length,Width,CanRotate,ExternalID,Priority)

#define IOptimization2DX_GetDemandPiece(This,Index,Length,Width,CanRotate,ExternalID,Priority)	\
    (This)->lpVtbl -> GetDemandPiece(This,Index,Length,Width,CanRotate,ExternalID,Priority)

#define IOptimization2DX_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#define IOptimization2DX_SetRepositoryPiece(This,Index,Length,Width,TrimTop,TrimLeft,TrimBottom,TrimRight,ExternalID,Priority,NumberOfHoles)	\
    (This)->lpVtbl -> SetRepositoryPiece(This,Index,Length,Width,TrimTop,TrimLeft,TrimBottom,TrimRight,ExternalID,Priority,NumberOfHoles)

#define IOptimization2DX_GetRepositoryPiece(This,Index,Length,Width,TrimTop,TrimLeft,TrimBottom,TrimRight,ExternalID,Priority,NumberOfHoles)	\
    (This)->lpVtbl -> GetRepositoryPiece(This,Index,Length,Width,TrimTop,TrimLeft,TrimBottom,TrimRight,ExternalID,Priority,NumberOfHoles)

#define IOptimization2DX_get_Version(This,Value)	\
    (This)->lpVtbl -> get_Version(This,Value)

#define IOptimization2DX_get_Expired(This,Value)	\
    (This)->lpVtbl -> get_Expired(This,Value)

#define IOptimization2DX_get_TotalNumberOfUtilizedDemandPieces(This,Value)	\
    (This)->lpVtbl -> get_TotalNumberOfUtilizedDemandPieces(This,Value)

#define IOptimization2DX_RegisterOptimization2DX(This,UserName,SerialNumber)	\
    (This)->lpVtbl -> RegisterOptimization2DX(This,UserName,SerialNumber)

#define IOptimization2DX_get_TotalNumberOfUtilizedRepositoryPieces(This,Value)	\
    (This)->lpVtbl -> get_TotalNumberOfUtilizedRepositoryPieces(This,Value)

#define IOptimization2DX_get_WhichStartMethodStarted(This,Value)	\
    (This)->lpVtbl -> get_WhichStartMethodStarted(This,Value)

#define IOptimization2DX_get_MinimalWidthBreakage(This,Value)	\
    (This)->lpVtbl -> get_MinimalWidthBreakage(This,Value)

#define IOptimization2DX_put_MinimalWidthBreakage(This,Value)	\
    (This)->lpVtbl -> put_MinimalWidthBreakage(This,Value)

#define IOptimization2DX_get_MaximalCutLength(This,Value)	\
    (This)->lpVtbl -> get_MaximalCutLength(This,Value)

#define IOptimization2DX_put_MaximalCutLength(This,Value)	\
    (This)->lpVtbl -> put_MaximalCutLength(This,Value)

#define IOptimization2DX_get_FirstDirectionMultiStages(This,Value)	\
    (This)->lpVtbl -> get_FirstDirectionMultiStages(This,Value)

#define IOptimization2DX_put_FirstDirectionMultiStages(This,Value)	\
    (This)->lpVtbl -> put_FirstDirectionMultiStages(This,Value)

#define IOptimization2DX_get_ShowWarnings(This,Value)	\
    (This)->lpVtbl -> get_ShowWarnings(This,Value)

#define IOptimization2DX_put_ShowWarnings(This,Value)	\
    (This)->lpVtbl -> put_ShowWarnings(This,Value)

#define IOptimization2DX_NumberOfCuttings(This,SheetIndex,NumberOfCuts,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> NumberOfCuttings(This,SheetIndex,NumberOfCuts,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_NumberOfUtilizedDemandPieces(This,SheetIndex,NumberOfUtilizedPieces,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> NumberOfUtilizedDemandPieces(This,SheetIndex,NumberOfUtilizedPieces,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_NumberOfWastePieces(This,SheetIndex,NumberOfWastePieces,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> NumberOfWastePieces(This,SheetIndex,NumberOfWastePieces,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_SurfaceCovered(This,SheetIndex,SurfaceCovered,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> SurfaceCovered(This,SheetIndex,SurfaceCovered,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_GetCut(This,SheetIndex,CutIndex,TopX,TopY,BottomX,BottomY,CutThickness,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> GetCut(This,SheetIndex,CutIndex,TopX,TopY,BottomX,BottomY,CutThickness,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_GetUtilizedDemandPiece(This,SheetIndex,PieceIndex,TopX,TopY,BottomX,BottomY,Rotated,RepositoryIndex,DemandIndex,RepositoryExternalID,DemandExternalID)	\
    (This)->lpVtbl -> GetUtilizedDemandPiece(This,SheetIndex,PieceIndex,TopX,TopY,BottomX,BottomY,Rotated,RepositoryIndex,DemandIndex,RepositoryExternalID,DemandExternalID)

#define IOptimization2DX_GetWastePiece(This,SheetIndex,WasteIndex,TopX,TopY,BottomX,BottomY,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> GetWastePiece(This,SheetIndex,WasteIndex,TopX,TopY,BottomX,BottomY,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_DemandPieceUtilized(This,DemandIndex,SheetIndex,RepositoryIndex,DemandExternalID,RepositoryExternalID)	\
    (This)->lpVtbl -> DemandPieceUtilized(This,DemandIndex,SheetIndex,RepositoryIndex,DemandExternalID,RepositoryExternalID)

#define IOptimization2DX_RepositoryPieceUtilized(This,Index,Utilized,RepositoryExternalID)	\
    (This)->lpVtbl -> RepositoryPieceUtilized(This,Index,Utilized,RepositoryExternalID)

#define IOptimization2DX_GetUtilizedRepositoryPiece(This,SheetIndex,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> GetUtilizedRepositoryPiece(This,SheetIndex,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_get_CutAllStripsFirst(This,Value)	\
    (This)->lpVtbl -> get_CutAllStripsFirst(This,Value)

#define IOptimization2DX_put_CutAllStripsFirst(This,Value)	\
    (This)->lpVtbl -> put_CutAllStripsFirst(This,Value)

#define IOptimization2DX_get_OnlyPiecesOfTheSameHeightInAStrip(This,Value)	\
    (This)->lpVtbl -> get_OnlyPiecesOfTheSameHeightInAStrip(This,Value)

#define IOptimization2DX_put_OnlyPiecesOfTheSameHeightInAStrip(This,Value)	\
    (This)->lpVtbl -> put_OnlyPiecesOfTheSameHeightInAStrip(This,Value)

#define IOptimization2DX_get_HeightTolerance(This,Value)	\
    (This)->lpVtbl -> get_HeightTolerance(This,Value)

#define IOptimization2DX_put_HeightTolerance(This,Value)	\
    (This)->lpVtbl -> put_HeightTolerance(This,Value)

#define IOptimization2DX_put_ManualArrangeNumberOfCuts(This,rhs)	\
    (This)->lpVtbl -> put_ManualArrangeNumberOfCuts(This,rhs)

#define IOptimization2DX_put_ManualArrangeNumberOfPieces(This,rhs)	\
    (This)->lpVtbl -> put_ManualArrangeNumberOfPieces(This,rhs)

#define IOptimization2DX_put_ManualArrangeNumberOfWastes(This,rhs)	\
    (This)->lpVtbl -> put_ManualArrangeNumberOfWastes(This,rhs)

#define IOptimization2DX_ManualArrangeSetCut(This,Index,TopX,TopY,BottomX,BottomY,CutThickness)	\
    (This)->lpVtbl -> ManualArrangeSetCut(This,Index,TopX,TopY,BottomX,BottomY,CutThickness)

#define IOptimization2DX_ManualArrangeSetPiecePosition(This,Index,TopX,TopY,BottomX,BottomY,Rotated,ExternalID)	\
    (This)->lpVtbl -> ManualArrangeSetPiecePosition(This,Index,TopX,TopY,BottomX,BottomY,Rotated,ExternalID)

#define IOptimization2DX_ManualArrangeSetWasteRectangle(This,Index,TopX,TopY,BottomX,BottomY)	\
    (This)->lpVtbl -> ManualArrangeSetWasteRectangle(This,Index,TopX,TopY,BottomX,BottomY)

#define IOptimization2DX_ManualArrangeGuillotineAddPiece(This,TopX,TopY,BottomX,BottomY,Rotated,CutType,ExternalID,IndexWasteRemoved,IndexWasteInserted1,IndexWasteInserted2,IndexCutInserted1,IndexCutInserted2,AllowAdd)	\
    (This)->lpVtbl -> ManualArrangeGuillotineAddPiece(This,TopX,TopY,BottomX,BottomY,Rotated,CutType,ExternalID,IndexWasteRemoved,IndexWasteInserted1,IndexWasteInserted2,IndexCutInserted1,IndexCutInserted2,AllowAdd)

#define IOptimization2DX_ManualArrangeIsValidPositionForAPiece(This,TopX,TopY,BottomX,BottomY,CutType,AllowCut)	\
    (This)->lpVtbl -> ManualArrangeIsValidPositionForAPiece(This,TopX,TopY,BottomX,BottomY,CutType,AllowCut)

#define IOptimization2DX_ManualArrangeNStagesAddPiece(This,TopX,TopY,BottomX,BottomY,Rotated,ExternalID,IndexWasteRemoved,IndexWasteInserted1,IndexWasteInserted2,IndexCutInserted1,IndexCutInserted2,AllowAdd)	\
    (This)->lpVtbl -> ManualArrangeNStagesAddPiece(This,TopX,TopY,BottomX,BottomY,Rotated,ExternalID,IndexWasteRemoved,IndexWasteInserted1,IndexWasteInserted2,IndexCutInserted1,IndexCutInserted2,AllowAdd)

#define IOptimization2DX_ManualArrangeGuillotineRemovePiece(This,IndexOfPiece)	\
    (This)->lpVtbl -> ManualArrangeGuillotineRemovePiece(This,IndexOfPiece)

#define IOptimization2DX_ManualArrangeGuillotineMovePiece(This,Index,TopX,TopY,BottomX,BottomY,Rotated,CutType,AllowMove)	\
    (This)->lpVtbl -> ManualArrangeGuillotineMovePiece(This,Index,TopX,TopY,BottomX,BottomY,Rotated,CutType,AllowMove)

#define IOptimization2DX_ManualArrangeAddCut(This,X,Y,CutType,CutThickness,AllowCut,IndexOfAddedCut,IndexOfRemovedWaste,IndexOfAddedWaste1,IndexOfAddedWaste2)	\
    (This)->lpVtbl -> ManualArrangeAddCut(This,X,Y,CutType,CutThickness,AllowCut,IndexOfAddedCut,IndexOfRemovedWaste,IndexOfAddedWaste1,IndexOfAddedWaste2)

#define IOptimization2DX_ManualArrangeGlueCuts(This,IndexCut1,IndexCut2,IndexCut3,IndexNewCut1,IndexNewCut2,IndexNewCut3,AllowJoin)	\
    (This)->lpVtbl -> ManualArrangeGlueCuts(This,IndexCut1,IndexCut2,IndexCut3,IndexNewCut1,IndexNewCut2,IndexNewCut3,AllowJoin)

#define IOptimization2DX_ManualArrangeRemoveCut(This,IndexCut,IndexRemovedWaste1,IndexRemovedWaste2,IndexInsertedWaste)	\
    (This)->lpVtbl -> ManualArrangeRemoveCut(This,IndexCut,IndexRemovedWaste1,IndexRemovedWaste2,IndexInsertedWaste)

#define IOptimization2DX_ManualArrangeSwitchCut(This,IndexCut,JoinPerformed)	\
    (This)->lpVtbl -> ManualArrangeSwitchCut(This,IndexCut,JoinPerformed)

#define IOptimization2DX_ManualArrangeIsValidSwitchCut(This,IndexCut,AllowSwitch)	\
    (This)->lpVtbl -> ManualArrangeIsValidSwitchCut(This,IndexCut,AllowSwitch)

#define IOptimization2DX_ManualArrangeIsValidRemoveCut(This,IndexCut,AllowRemove)	\
    (This)->lpVtbl -> ManualArrangeIsValidRemoveCut(This,IndexCut,AllowRemove)

#define IOptimization2DX_ManualArrangeSwitchCutOrientation(This,IndexCut,X,Y,AllowSwitchOrientation)	\
    (This)->lpVtbl -> ManualArrangeSwitchCutOrientation(This,IndexCut,X,Y,AllowSwitchOrientation)

#define IOptimization2DX_ManualArrangeIsValidSwitchCutOrientation(This,IndexCut,X,Y,AllowSwitchOrientation)	\
    (This)->lpVtbl -> ManualArrangeIsValidSwitchCutOrientation(This,IndexCut,X,Y,AllowSwitchOrientation)

#define IOptimization2DX_ManualArrangeIsValidAddCut(This,X,Y,CutType,CutThickness,AllowAddCut)	\
    (This)->lpVtbl -> ManualArrangeIsValidAddCut(This,X,Y,CutType,CutThickness,AllowAddCut)

#define IOptimization2DX_get_ManualArrangeOptimizationType(This,Value)	\
    (This)->lpVtbl -> get_ManualArrangeOptimizationType(This,Value)

#define IOptimization2DX_put_ManualArrangeOptimizationType(This,Value)	\
    (This)->lpVtbl -> put_ManualArrangeOptimizationType(This,Value)

#define IOptimization2DX_ManualArrangeGuillotineIsValidPositionForAPiece(This,TopX,TopY,BottomX,BottomY,CutType,AllowCut)	\
    (This)->lpVtbl -> ManualArrangeGuillotineIsValidPositionForAPiece(This,TopX,TopY,BottomX,BottomY,CutType,AllowCut)

#define IOptimization2DX_get_TrimType(This,Value)	\
    (This)->lpVtbl -> get_TrimType(This,Value)

#define IOptimization2DX_put_TrimType(This,Value)	\
    (This)->lpVtbl -> put_TrimType(This,Value)

#define IOptimization2DX_get_NumberOfStages(This,Value)	\
    (This)->lpVtbl -> get_NumberOfStages(This,Value)

#define IOptimization2DX_put_NumberOfStages(This,Value)	\
    (This)->lpVtbl -> put_NumberOfStages(This,Value)

#define IOptimization2DX_SaveToFile(This,FileName,SaveInputData,SaveParameters,SaveResults)	\
    (This)->lpVtbl -> SaveToFile(This,FileName,SaveInputData,SaveParameters,SaveResults)

#define IOptimization2DX_LoadFromFile(This,FileName)	\
    (This)->lpVtbl -> LoadFromFile(This,FileName)

#define IOptimization2DX_SetRepositoryHole(This,RepositoryIndex,HoleIndex,TopX,TopY,BottomX,BottomY,ExternalIDofHole)	\
    (This)->lpVtbl -> SetRepositoryHole(This,RepositoryIndex,HoleIndex,TopX,TopY,BottomX,BottomY,ExternalIDofHole)

#define IOptimization2DX_GetRepositoryHole(This,RepositoryIndex,HoleIndex,TopX,TopY,BottomX,BottomY,ExternalIDofHole)	\
    (This)->lpVtbl -> GetRepositoryHole(This,RepositoryIndex,HoleIndex,TopX,TopY,BottomX,BottomY,ExternalIDofHole)

#define IOptimization2DX_BasicCNC(This,SheetIndex,CNC,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> BasicCNC(This,SheetIndex,CNC,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_put_Identification(This,rhs)	\
    (This)->lpVtbl -> put_Identification(This,rhs)

#define IOptimization2DX_get_MinimalUsefulSize(This,Value)	\
    (This)->lpVtbl -> get_MinimalUsefulSize(This,Value)

#define IOptimization2DX_put_MinimalUsefulSize(This,Value)	\
    (This)->lpVtbl -> put_MinimalUsefulSize(This,Value)

#define IOptimization2DX_get_MinStripSize(This,Value)	\
    (This)->lpVtbl -> get_MinStripSize(This,Value)

#define IOptimization2DX_put_MinStripSize(This,Value)	\
    (This)->lpVtbl -> put_MinStripSize(This,Value)

#define IOptimization2DX_get_MaxStripSize(This,Value)	\
    (This)->lpVtbl -> get_MaxStripSize(This,Value)

#define IOptimization2DX_put_MaxStripSize(This,Value)	\
    (This)->lpVtbl -> put_MaxStripSize(This,Value)

#define IOptimization2DX_get_AllowPrecuts(This,Value)	\
    (This)->lpVtbl -> get_AllowPrecuts(This,Value)

#define IOptimization2DX_put_AllowPrecuts(This,Value)	\
    (This)->lpVtbl -> put_AllowPrecuts(This,Value)

#define IOptimization2DX_get_PrecutDirection(This,Value)	\
    (This)->lpVtbl -> get_PrecutDirection(This,Value)

#define IOptimization2DX_put_PrecutDirection(This,Value)	\
    (This)->lpVtbl -> put_PrecutDirection(This,Value)

#define IOptimization2DX_get_GenerateBasicCNC(This,Value)	\
    (This)->lpVtbl -> get_GenerateBasicCNC(This,Value)

#define IOptimization2DX_put_GenerateBasicCNC(This,Value)	\
    (This)->lpVtbl -> put_GenerateBasicCNC(This,Value)

#define IOptimization2DX_WasteSurface(This,SheetIndex,Surface,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> WasteSurface(This,SheetIndex,Surface,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_GarbageWaste(This,SheetIndex,Surface,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> GarbageWaste(This,SheetIndex,Surface,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_CutSurface(This,SheetIndex,Surface,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> CutSurface(This,SheetIndex,Surface,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_CutLength(This,SheetIndex,Length,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> CutLength(This,SheetIndex,Length,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_StartNestingRolls(This)	\
    (This)->lpVtbl -> StartNestingRolls(This)

#define IOptimization2DX_BasicCNCNumberOfCuts(This,SheetIndex,NumberOfCuts,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> BasicCNCNumberOfCuts(This,SheetIndex,NumberOfCuts,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_BasicCNCGetCut(This,SheetIndex,CutIndex,TopX,TopY,BottomX,BottomY,CutThickness,Level,Type,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> BasicCNCGetCut(This,SheetIndex,CutIndex,TopX,TopY,BottomX,BottomY,CutThickness,Level,Type,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_GetCutMultiStages(This,SheetIndex,CutIndex,TopX,TopY,BottomX,BottomY,CutThickness,Level,RepositoryIndex,RepositoryExternalID)	\
    (This)->lpVtbl -> GetCutMultiStages(This,SheetIndex,CutIndex,TopX,TopY,BottomX,BottomY,CutThickness,Level,RepositoryIndex,RepositoryExternalID)

#define IOptimization2DX_get_MaximalGarbageSize(This,Value)	\
    (This)->lpVtbl -> get_MaximalGarbageSize(This,Value)

#define IOptimization2DX_put_MaximalGarbageSize(This,Value)	\
    (This)->lpVtbl -> put_MaximalGarbageSize(This,Value)

#define IOptimization2DX_get_SinglePieceStrips(This,Value)	\
    (This)->lpVtbl -> get_SinglePieceStrips(This,Value)

#define IOptimization2DX_put_SinglePieceStrips(This,Value)	\
    (This)->lpVtbl -> put_SinglePieceStrips(This,Value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_OptimizationLevel_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_OptimizationLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_OptimizationLevel_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_OptimizationLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_BladeWidth_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_BladeWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_BladeWidth_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_BladeWidth_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_NumberOfDemandPieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_NumberOfDemandPieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_NumberOfDemandPieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_NumberOfDemandPieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_RandomSeed_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_RandomSeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_RandomSeed_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_RandomSeed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_ComputerID_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_ComputerID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_IsRegistered_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_IsRegistered_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_NumberOfRepositoryPieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_NumberOfRepositoryPieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_NumberOfRepositoryPieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_NumberOfRepositoryPieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_CallerName_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_CallerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_StartGuillotine_Proxy( 
    IOptimization2DX __RPC_FAR * This);


void __RPC_STUB IOptimization2DX_StartGuillotine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_StartNested_Proxy( 
    IOptimization2DX __RPC_FAR * This);


void __RPC_STUB IOptimization2DX_StartNested_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_StartMultiStages_Proxy( 
    IOptimization2DX __RPC_FAR * This);


void __RPC_STUB IOptimization2DX_StartMultiStages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_SetDemandPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [in] */ long Length,
    /* [in] */ long Width,
    /* [in] */ long CanRotate,
    /* [in] */ long ExternalID,
    /* [in] */ long Priority);


void __RPC_STUB IOptimization2DX_SetDemandPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GetDemandPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [out] */ long __RPC_FAR *Length,
    /* [out] */ long __RPC_FAR *Width,
    /* [out] */ long __RPC_FAR *CanRotate,
    /* [out] */ long __RPC_FAR *ExternalID,
    /* [out] */ long __RPC_FAR *Priority);


void __RPC_STUB IOptimization2DX_GetDemandPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_Stop_Proxy( 
    IOptimization2DX __RPC_FAR * This);


void __RPC_STUB IOptimization2DX_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_SetRepositoryPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [in] */ long Length,
    /* [in] */ long Width,
    /* [in] */ long TrimTop,
    /* [in] */ long TrimLeft,
    /* [in] */ long TrimBottom,
    /* [in] */ long TrimRight,
    /* [in] */ long ExternalID,
    /* [in] */ long Priority,
    /* [in] */ long NumberOfHoles);


void __RPC_STUB IOptimization2DX_SetRepositoryPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GetRepositoryPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [out] */ long __RPC_FAR *Length,
    /* [out] */ long __RPC_FAR *Width,
    /* [out] */ long __RPC_FAR *TrimTop,
    /* [out] */ long __RPC_FAR *TrimLeft,
    /* [out] */ long __RPC_FAR *TrimBottom,
    /* [out] */ long __RPC_FAR *TrimRight,
    /* [out] */ long __RPC_FAR *ExternalID,
    /* [out] */ long __RPC_FAR *Priority,
    /* [out] */ long __RPC_FAR *NumberOfHoles);


void __RPC_STUB IOptimization2DX_GetRepositoryPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_Version_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_Version_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_Expired_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_Expired_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_TotalNumberOfUtilizedDemandPieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_TotalNumberOfUtilizedDemandPieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_RegisterOptimization2DX_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ BSTR UserName,
    /* [in] */ BSTR SerialNumber);


void __RPC_STUB IOptimization2DX_RegisterOptimization2DX_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_TotalNumberOfUtilizedRepositoryPieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_TotalNumberOfUtilizedRepositoryPieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_WhichStartMethodStarted_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_WhichStartMethodStarted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_MinimalWidthBreakage_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_MinimalWidthBreakage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_MinimalWidthBreakage_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_MinimalWidthBreakage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_MaximalCutLength_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_MaximalCutLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_MaximalCutLength_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_MaximalCutLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_FirstDirectionMultiStages_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_FirstDirectionMultiStages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_FirstDirectionMultiStages_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_FirstDirectionMultiStages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_ShowWarnings_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_ShowWarnings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_ShowWarnings_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_ShowWarnings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_NumberOfCuttings_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ long __RPC_FAR *NumberOfCuts,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_NumberOfCuttings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_NumberOfUtilizedDemandPieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ long __RPC_FAR *NumberOfUtilizedPieces,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_NumberOfUtilizedDemandPieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_NumberOfWastePieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ long __RPC_FAR *NumberOfWastePieces,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_NumberOfWastePieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_SurfaceCovered_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ double __RPC_FAR *SurfaceCovered,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_SurfaceCovered_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GetCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [in] */ long CutIndex,
    /* [out] */ long __RPC_FAR *TopX,
    /* [out] */ long __RPC_FAR *TopY,
    /* [out] */ long __RPC_FAR *BottomX,
    /* [out] */ long __RPC_FAR *BottomY,
    /* [out] */ long __RPC_FAR *CutThickness,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_GetCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GetUtilizedDemandPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [in] */ long PieceIndex,
    /* [out] */ long __RPC_FAR *TopX,
    /* [out] */ long __RPC_FAR *TopY,
    /* [out] */ long __RPC_FAR *BottomX,
    /* [out] */ long __RPC_FAR *BottomY,
    /* [out] */ long __RPC_FAR *Rotated,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *DemandIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID,
    /* [out] */ long __RPC_FAR *DemandExternalID);


void __RPC_STUB IOptimization2DX_GetUtilizedDemandPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GetWastePiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [in] */ long WasteIndex,
    /* [out] */ long __RPC_FAR *TopX,
    /* [out] */ long __RPC_FAR *TopY,
    /* [out] */ long __RPC_FAR *BottomX,
    /* [out] */ long __RPC_FAR *BottomY,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_GetWastePiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_DemandPieceUtilized_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long DemandIndex,
    /* [out] */ long __RPC_FAR *SheetIndex,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *DemandExternalID,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_DemandPieceUtilized_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_RepositoryPieceUtilized_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [out] */ long __RPC_FAR *Utilized,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_RepositoryPieceUtilized_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GetUtilizedRepositoryPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_GetUtilizedRepositoryPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_CutAllStripsFirst_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_CutAllStripsFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_CutAllStripsFirst_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_CutAllStripsFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_OnlyPiecesOfTheSameHeightInAStrip_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_OnlyPiecesOfTheSameHeightInAStrip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_OnlyPiecesOfTheSameHeightInAStrip_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_OnlyPiecesOfTheSameHeightInAStrip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_HeightTolerance_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_HeightTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_HeightTolerance_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_HeightTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_ManualArrangeNumberOfCuts_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long rhs);


void __RPC_STUB IOptimization2DX_put_ManualArrangeNumberOfCuts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_ManualArrangeNumberOfPieces_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long rhs);


void __RPC_STUB IOptimization2DX_put_ManualArrangeNumberOfPieces_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_ManualArrangeNumberOfWastes_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long rhs);


void __RPC_STUB IOptimization2DX_put_ManualArrangeNumberOfWastes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeSetCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY,
    /* [in] */ long CutThickness);


void __RPC_STUB IOptimization2DX_ManualArrangeSetCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeSetPiecePosition_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY,
    /* [in] */ long Rotated,
    /* [in] */ long ExternalID);


void __RPC_STUB IOptimization2DX_ManualArrangeSetPiecePosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeSetWasteRectangle_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY);


void __RPC_STUB IOptimization2DX_ManualArrangeSetWasteRectangle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeGuillotineAddPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY,
    /* [in] */ long Rotated,
    /* [in] */ long CutType,
    /* [in] */ long ExternalID,
    /* [out] */ long __RPC_FAR *IndexWasteRemoved,
    /* [out] */ long __RPC_FAR *IndexWasteInserted1,
    /* [out] */ long __RPC_FAR *IndexWasteInserted2,
    /* [out] */ long __RPC_FAR *IndexCutInserted1,
    /* [out] */ long __RPC_FAR *IndexCutInserted2,
    /* [out] */ long __RPC_FAR *AllowAdd);


void __RPC_STUB IOptimization2DX_ManualArrangeGuillotineAddPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeIsValidPositionForAPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY,
    /* [in] */ long CutType,
    /* [out] */ long __RPC_FAR *AllowCut);


void __RPC_STUB IOptimization2DX_ManualArrangeIsValidPositionForAPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeNStagesAddPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY,
    /* [in] */ long Rotated,
    /* [in] */ long ExternalID,
    /* [out] */ long __RPC_FAR *IndexWasteRemoved,
    /* [out] */ long __RPC_FAR *IndexWasteInserted1,
    /* [out] */ long __RPC_FAR *IndexWasteInserted2,
    /* [out] */ long __RPC_FAR *IndexCutInserted1,
    /* [out] */ long __RPC_FAR *IndexCutInserted2,
    /* [out] */ long __RPC_FAR *AllowAdd);


void __RPC_STUB IOptimization2DX_ManualArrangeNStagesAddPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeGuillotineRemovePiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long IndexOfPiece);


void __RPC_STUB IOptimization2DX_ManualArrangeGuillotineRemovePiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeGuillotineMovePiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Index,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY,
    /* [in] */ long Rotated,
    /* [in] */ long CutType,
    /* [out] */ long __RPC_FAR *AllowMove);


void __RPC_STUB IOptimization2DX_ManualArrangeGuillotineMovePiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeAddCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long X,
    /* [in] */ long Y,
    /* [in] */ long CutType,
    /* [in] */ long CutThickness,
    /* [out] */ long __RPC_FAR *AllowCut,
    /* [out] */ long __RPC_FAR *IndexOfAddedCut,
    /* [out] */ long __RPC_FAR *IndexOfRemovedWaste,
    /* [out] */ long __RPC_FAR *IndexOfAddedWaste1,
    /* [out] */ long __RPC_FAR *IndexOfAddedWaste2);


void __RPC_STUB IOptimization2DX_ManualArrangeAddCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeGlueCuts_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long IndexCut1,
    /* [in] */ long IndexCut2,
    /* [in] */ long IndexCut3,
    /* [out] */ long __RPC_FAR *IndexNewCut1,
    /* [out] */ long __RPC_FAR *IndexNewCut2,
    /* [out] */ long __RPC_FAR *IndexNewCut3,
    /* [out] */ long __RPC_FAR *AllowJoin);


void __RPC_STUB IOptimization2DX_ManualArrangeGlueCuts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeRemoveCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long IndexCut,
    /* [out] */ long __RPC_FAR *IndexRemovedWaste1,
    /* [out] */ long __RPC_FAR *IndexRemovedWaste2,
    /* [out] */ long __RPC_FAR *IndexInsertedWaste);


void __RPC_STUB IOptimization2DX_ManualArrangeRemoveCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeSwitchCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long IndexCut,
    /* [out] */ long __RPC_FAR *JoinPerformed);


void __RPC_STUB IOptimization2DX_ManualArrangeSwitchCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeIsValidSwitchCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long IndexCut,
    /* [out] */ long __RPC_FAR *AllowSwitch);


void __RPC_STUB IOptimization2DX_ManualArrangeIsValidSwitchCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeIsValidRemoveCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long IndexCut,
    /* [out] */ long __RPC_FAR *AllowRemove);


void __RPC_STUB IOptimization2DX_ManualArrangeIsValidRemoveCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeSwitchCutOrientation_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long IndexCut,
    /* [in] */ long X,
    /* [in] */ long Y,
    /* [out] */ long __RPC_FAR *AllowSwitchOrientation);


void __RPC_STUB IOptimization2DX_ManualArrangeSwitchCutOrientation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeIsValidSwitchCutOrientation_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long IndexCut,
    /* [in] */ long X,
    /* [in] */ long Y,
    /* [out] */ long __RPC_FAR *AllowSwitchOrientation);


void __RPC_STUB IOptimization2DX_ManualArrangeIsValidSwitchCutOrientation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeIsValidAddCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long X,
    /* [in] */ long Y,
    /* [in] */ long CutType,
    /* [in] */ long CutThickness,
    /* [out] */ long __RPC_FAR *AllowAddCut);


void __RPC_STUB IOptimization2DX_ManualArrangeIsValidAddCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_ManualArrangeOptimizationType_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_ManualArrangeOptimizationType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_ManualArrangeOptimizationType_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_ManualArrangeOptimizationType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_ManualArrangeGuillotineIsValidPositionForAPiece_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY,
    /* [in] */ long CutType,
    /* [out] */ long __RPC_FAR *AllowCut);


void __RPC_STUB IOptimization2DX_ManualArrangeGuillotineIsValidPositionForAPiece_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_TrimType_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_TrimType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_TrimType_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_TrimType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_NumberOfStages_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_NumberOfStages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_NumberOfStages_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_NumberOfStages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_SaveToFile_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ BSTR FileName,
    /* [in] */ long SaveInputData,
    /* [in] */ long SaveParameters,
    /* [in] */ long SaveResults);


void __RPC_STUB IOptimization2DX_SaveToFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_LoadFromFile_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB IOptimization2DX_LoadFromFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_SetRepositoryHole_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long RepositoryIndex,
    /* [in] */ long HoleIndex,
    /* [in] */ long TopX,
    /* [in] */ long TopY,
    /* [in] */ long BottomX,
    /* [in] */ long BottomY,
    /* [in] */ long ExternalIDofHole);


void __RPC_STUB IOptimization2DX_SetRepositoryHole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GetRepositoryHole_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long RepositoryIndex,
    /* [in] */ long HoleIndex,
    /* [out] */ long __RPC_FAR *TopX,
    /* [out] */ long __RPC_FAR *TopY,
    /* [out] */ long __RPC_FAR *BottomX,
    /* [out] */ long __RPC_FAR *BottomY,
    /* [out] */ long __RPC_FAR *ExternalIDofHole);


void __RPC_STUB IOptimization2DX_GetRepositoryHole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_BasicCNC_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ BSTR __RPC_FAR *CNC,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_BasicCNC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_Identification_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long rhs);


void __RPC_STUB IOptimization2DX_put_Identification_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_MinimalUsefulSize_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_MinimalUsefulSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_MinimalUsefulSize_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_MinimalUsefulSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_MinStripSize_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_MinStripSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_MinStripSize_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_MinStripSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_MaxStripSize_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_MaxStripSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_MaxStripSize_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_MaxStripSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_AllowPrecuts_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_AllowPrecuts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_AllowPrecuts_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_AllowPrecuts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_PrecutDirection_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_PrecutDirection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_PrecutDirection_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_PrecutDirection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_GenerateBasicCNC_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_GenerateBasicCNC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_GenerateBasicCNC_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_GenerateBasicCNC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_WasteSurface_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ double __RPC_FAR *Surface,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_WasteSurface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GarbageWaste_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ double __RPC_FAR *Surface,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_GarbageWaste_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_CutSurface_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ double __RPC_FAR *Surface,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_CutSurface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_CutLength_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ double __RPC_FAR *Length,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_CutLength_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_StartNestingRolls_Proxy( 
    IOptimization2DX __RPC_FAR * This);


void __RPC_STUB IOptimization2DX_StartNestingRolls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_BasicCNCNumberOfCuts_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [out] */ long __RPC_FAR *NumberOfCuts,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_BasicCNCNumberOfCuts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_BasicCNCGetCut_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [in] */ long CutIndex,
    /* [out] */ long __RPC_FAR *TopX,
    /* [out] */ long __RPC_FAR *TopY,
    /* [out] */ long __RPC_FAR *BottomX,
    /* [out] */ long __RPC_FAR *BottomY,
    /* [out] */ long __RPC_FAR *CutThickness,
    /* [out] */ long __RPC_FAR *Level,
    /* [out] */ long __RPC_FAR *Type,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_BasicCNCGetCut_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_GetCutMultiStages_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long SheetIndex,
    /* [in] */ long CutIndex,
    /* [out] */ long __RPC_FAR *TopX,
    /* [out] */ long __RPC_FAR *TopY,
    /* [out] */ long __RPC_FAR *BottomX,
    /* [out] */ long __RPC_FAR *BottomY,
    /* [out] */ long __RPC_FAR *CutThickness,
    /* [out] */ long __RPC_FAR *Level,
    /* [out] */ long __RPC_FAR *RepositoryIndex,
    /* [out] */ long __RPC_FAR *RepositoryExternalID);


void __RPC_STUB IOptimization2DX_GetCutMultiStages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_MaximalGarbageSize_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_MaximalGarbageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_MaximalGarbageSize_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_MaximalGarbageSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_get_SinglePieceStrips_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Value);


void __RPC_STUB IOptimization2DX_get_SinglePieceStrips_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE IOptimization2DX_put_SinglePieceStrips_Proxy( 
    IOptimization2DX __RPC_FAR * This,
    /* [in] */ long Value);


void __RPC_STUB IOptimization2DX_put_SinglePieceStrips_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOptimization2DX_INTERFACE_DEFINED__ */


#ifndef __IOptimization2DXEvents_DISPINTERFACE_DEFINED__
#define __IOptimization2DXEvents_DISPINTERFACE_DEFINED__

/* dispinterface IOptimization2DXEvents */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID DIID_IOptimization2DXEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("E8BE5D3C-9B56-4892-8F45-3CC008857C63")
    IOptimization2DXEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct IOptimization2DXEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOptimization2DXEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOptimization2DXEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOptimization2DXEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOptimization2DXEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOptimization2DXEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOptimization2DXEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOptimization2DXEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } IOptimization2DXEventsVtbl;

    interface IOptimization2DXEvents
    {
        CONST_VTBL struct IOptimization2DXEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOptimization2DXEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOptimization2DXEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOptimization2DXEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOptimization2DXEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOptimization2DXEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOptimization2DXEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOptimization2DXEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* __IOptimization2DXEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_Optimization2DX;

#ifdef __cplusplus

class DECLSPEC_UUID("50C1F407-FFDB-4A07-8AD8-356579BF3A40")
Optimization2DX;
#endif
#endif /* __optimal2dx_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
