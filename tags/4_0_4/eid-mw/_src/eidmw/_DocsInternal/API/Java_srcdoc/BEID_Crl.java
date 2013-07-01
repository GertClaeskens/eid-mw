/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 1.3.35
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */

package be.belgium.eid;

/******************************************************************************//**
  * Class that represents a CRL
  *********************************************************************************/
public class BEID_Crl extends BEID_Object {
  private long swigCPtr;

  protected BEID_Crl(long cPtr, boolean cMemoryOwn) {
    super(beidlibJava_WrapperJNI.SWIGBEID_CrlUpcast(cPtr), cMemoryOwn);
    swigCPtr = cPtr;
  }

  protected static long getCPtr(BEID_Crl obj) {
    return (obj == null) ? 0 : obj.swigCPtr;
  }

  protected void finalize() {
    delete();
  }

  public synchronized void delete() {
    if(swigCPtr != 0 && swigCMemOwn) {
      swigCMemOwn = false;
      beidlibJava_WrapperJNI.delete_BEID_Crl(swigCPtr);
    }
    swigCPtr = 0;
    super.delete();
  }

	/**
	  * Create a Crl object from using the uri (without any certificate link);
	  * As there is no issuer, this CRL can't be verify and some methods are not allowed
	  * (ex. getIssuer()).
	  * These methods throw a BEID_ExBadUsage exception
	  */
  public BEID_Crl(String uri) {
    this(beidlibJava_WrapperJNI.new_BEID_Crl(uri), true);
  }

	/** Return the uri of the CRL */
  public String getUri() throws java.lang.Exception {
    return beidlibJava_WrapperJNI.BEID_Crl_getUri(swigCPtr, this);
  }

	/** Return the name of the issuer of the certificate */
  public String getIssuerName() throws java.lang.Exception {
    return beidlibJava_WrapperJNI.BEID_Crl_getIssuerName(swigCPtr, this);
  }

	/**
	  * Return the issuer certificate;
	  *
	  * if there is no issuer (root), a BEID_ExCertNoIssuer exception is thrown
	  */
  public BEID_Certificate getIssuer() throws java.lang.Exception {
    return new BEID_Certificate(beidlibJava_WrapperJNI.BEID_Crl_getIssuer(swigCPtr, this), false);
  }

	/**
	  * Return the CRL as a byte array
	  * If the CRL comes from a certificate we verify the signature
	  * If the CRL is created from the URL only we DON'T verify the signature
	  * @param crl will contain the crl
	  * @param bForceDownload if true, a new CRL will be downloaded, otherwise the CRL cache will be used
	  * @return Status of the CRL \see BEID_CrlStatus
	  */
  public BEID_CrlStatus getData(BEID_ByteArray crl, boolean bForceDownload) throws java.lang.Exception {
    return BEID_CrlStatus.swigToEnum(beidlibJava_WrapperJNI.BEID_Crl_getData__SWIG_0(swigCPtr, this, BEID_ByteArray.getCPtr(crl), crl, bForceDownload));
  }

	/**
	  * Return the CRL as a byte array
	  * If the CRL comes from a certificate we verify the signature
	  * If the CRL is created from the URL only we DON'T verify the signature
	  * @param crl will contain the crl. The CRL cache will be used by default
	  * @return Status of the CRL \see BEID_CrlStatus
	  */
  public BEID_CrlStatus getData(BEID_ByteArray crl) throws java.lang.Exception {
    return BEID_CrlStatus.swigToEnum(beidlibJava_WrapperJNI.BEID_Crl_getData__SWIG_1(swigCPtr, this, BEID_ByteArray.getCPtr(crl), crl));
  }

}