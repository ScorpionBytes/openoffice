/**************************************************************
 * 
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 * 
 *************************************************************/



#ifndef _SVX_ACCESSIBLE_HYPERLINK_HXX
#define _SVX_ACCESSIBLE_HYPERLINK_HXX

#include <cppuhelper/weakref.hxx>
#include <cppuhelper/compbase1.hxx>
#include <cppuhelper/typeprovider.hxx>
#include <cppuhelper/interfacecontainer.hxx>

#include <com/sun/star/uno/Reference.hxx>
#include <com/sun/star/lang/XServiceInfo.hpp>
#include <com/sun/star/accessibility/XAccessibleHyperlink.hpp>

#include <tools/solar.h>

class SvxFieldItem;
class SvxAccessibleTextAdapter;

namespace accessibility
{

    class AccessibleHyperlink : public ::cppu::WeakImplHelper1< ::com::sun::star::accessibility::XAccessibleHyperlink >
    {
    private:
        
        SvxAccessibleTextAdapter& rTA;
        SvxFieldItem* pFld;
    	// EE values
    	sal_uInt32 nPara;
    	sal_uInt16 nRealIdx;
    	sal_Int32 nStartIdx, nEndIdx;   // translated values
    	::rtl::OUString aDescription;

    public:
    	AccessibleHyperlink( SvxAccessibleTextAdapter& r, SvxFieldItem* p, sal_uInt32 nP, sal_uInt16 nR, sal_Int32 nStt, sal_Int32 nEnd, const ::rtl::OUString& rD );
    	~AccessibleHyperlink();
    	
    	// XAccessibleAction
        virtual sal_Int32 SAL_CALL getAccessibleActionCount() throw (::com::sun::star::uno::RuntimeException);
        virtual sal_Bool SAL_CALL doAccessibleAction( sal_Int32 nIndex ) throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::uno::RuntimeException);
        virtual ::rtl::OUString SAL_CALL getAccessibleActionDescription( sal_Int32 nIndex ) throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::uno::RuntimeException);
        virtual ::com::sun::star::uno::Reference< ::com::sun::star::accessibility::XAccessibleKeyBinding > SAL_CALL getAccessibleActionKeyBinding( sal_Int32 nIndex ) throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::uno::RuntimeException);    	
    
    	// XAccessibleHyperlink
        virtual ::com::sun::star::uno::Any SAL_CALL getAccessibleActionAnchor( sal_Int32 nIndex ) throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::uno::RuntimeException);
        virtual ::com::sun::star::uno::Any SAL_CALL getAccessibleActionObject( sal_Int32 nIndex ) throw (::com::sun::star::lang::IndexOutOfBoundsException, ::com::sun::star::uno::RuntimeException);
        virtual sal_Int32 SAL_CALL getStartIndex() throw (::com::sun::star::uno::RuntimeException);
        virtual sal_Int32 SAL_CALL getEndIndex() throw (::com::sun::star::uno::RuntimeException);
        virtual sal_Bool SAL_CALL isValid() throw (::com::sun::star::uno::RuntimeException);
    };

} // end of namespace accessibility

#endif

