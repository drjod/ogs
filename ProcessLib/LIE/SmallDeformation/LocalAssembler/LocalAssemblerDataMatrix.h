/**
 * \copyright
 * Copyright (c) 2012-2016, OpenGeoSys Community (http://www.opengeosys.org)
 *            Distributed under a Modified BSD License.
 *              See accompanying file LICENSE.txt or
 *              http://www.opengeosys.org/project/license
 *
 */

#ifndef PROCESSLIB_LIE_SMALLDEFORMATION_LOCALASSEMBLERDATA_H_
#define PROCESSLIB_LIE_SMALLDEFORMATION_LOCALASSEMBLERDATA_H_

#include "SmallDeformationLocalAssemblerMatrix.h"

namespace ProcessLib
{
namespace LIE
{
namespace SmallDeformation
{

template <typename ShapeFunction, typename IntegrationMethod,
          unsigned GlobalDim, int DisplacementDim>
class LocalAssemblerDataMatrix final
    : public SmallDeformationLocalAssemblerMatrix<ShapeFunction, IntegrationMethod,
                                            DisplacementDim>
{
public:
    LocalAssemblerDataMatrix(LocalAssemblerDataMatrix const&) = delete;
    LocalAssemblerDataMatrix(LocalAssemblerDataMatrix&&) = delete;

    LocalAssemblerDataMatrix(
        MeshLib::Element const& e,
        std::size_t const local_matrix_size,
        bool const is_axially_symmetric,
        unsigned const integration_order,
        SmallDeformationProcessData<DisplacementDim>& process_data)
        : SmallDeformationLocalAssemblerMatrix<ShapeFunction, IntegrationMethod,
                                         DisplacementDim>(
              e, local_matrix_size, is_axially_symmetric, integration_order,
              process_data)
    {
    }
};

}  // namespace SmallDeformation
}  // namespace LIE
}  // namespace ProcessLib

#endif  // PROCESSLIB_LIE_SMALLDEFORMATION_LOCALASSEMBLERDATA_H_
