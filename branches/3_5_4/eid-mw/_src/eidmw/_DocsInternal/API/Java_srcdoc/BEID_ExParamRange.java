/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.35
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package be.belgium.eid;

/******************************************************************************//**
  * Exception class Bad Parameter Range (error code = EIDMW_ERR_PARAM_RANGE)
  *
  *	Thrown when the index is out of range
  * Used in : - BEID_ReaderSet.getReaderName(int ulIndex)
  *           - BEID_ReaderSet.getReaderByNum(int ulIndex)
  *           - BEID_Certificate.getChildren(int ulIndex)
  *           - BEID_Certificates.getCertByNumber(int ulIndex)
  *           - BEID_Pins.getPinByNumber(int ulIndex)
  *********************************************************************************/
public class BEID_ExParamRange extends BEID_Exception {
  private long swigCPtr;

  protected BEID_ExParamRange(long cPtr, boolean cMemoryOwn) {
    super(beidlibJava_WrapperJNI.SWIGBEID_ExParamRangeUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(BEID_ExParamRange obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      beidlibJava_WrapperJNI.delete_BEID_ExParamRange(swigCPtr);
    }
    swigCPtr = 0;
    super.delete();
  }

	/** Constructor */
  public BEID_ExParamRange() {
    this(beidlibJava_WrapperJNI.new_BEID_ExParamRange(), true);
  }

}
