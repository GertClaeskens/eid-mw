/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.35
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

namespace be.belgium.eid {

using System;
using System.Runtime.InteropServices;

/// <summary>
/// Exception class Bad Parameter Range (error code = EIDMW_ERR_PARAM_RANGE).
/// Throw when the element ask is out of range.
/// Used in : 
/// - BEID_ReaderSet::getReaderName(unsigned long ulIndex) 
/// - BEID_ReaderSet::getReaderByNum(unsigned long ulIndex) 
/// - BEID_Certificate::getChildren(unsigned long ulIndex)
/// - BEID_Certificates::getCertByNumber(unsigned long ulIndex)
/// - BEID_Pins::getPinByNumber(unsigned long ulIndex)
/// </summary>
public class BEID_ExParamRange : BEID_Exception {
  private HandleRef swigCPtr;

  internal BEID_ExParamRange(IntPtr cPtr, bool cMemoryOwn) : base(beidlib_dotNetPINVOKE.BEID_ExParamRangeUpcast(cPtr), cMemoryOwn) {
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(BEID_ExParamRange obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~BEID_ExParamRange() {
    Dispose();
  }

  public override void Dispose() {
    lock(this) {
      if(swigCPtr.Handle != IntPtr.Zero && swigCMemOwn) {
        swigCMemOwn = false;
        beidlib_dotNetPINVOKE.delete_BEID_ExParamRange(swigCPtr);
      }
      swigCPtr = new HandleRef(null, IntPtr.Zero);
      GC.SuppressFinalize(this);
      base.Dispose();
    }
  }

  public BEID_ExParamRange() : this(beidlib_dotNetPINVOKE.new_BEID_ExParamRange(), true) {
  }

}

}
