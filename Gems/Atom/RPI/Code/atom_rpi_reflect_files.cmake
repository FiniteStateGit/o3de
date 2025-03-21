#
# Copyright (c) Contributors to the Open 3D Engine Project.
# For complete copyright and license terms please see the LICENSE at the root of this distribution.
#
# SPDX-License-Identifier: Apache-2.0 OR MIT
#
#

set(FILES
    Include/Atom/RPI.Reflect/AssetCreator.h
    Include/Atom/RPI.Reflect/Base.h
    Include/Atom/RPI.Reflect/FeatureProcessorDescriptor.h
    Include/Atom/RPI.Reflect/GpuQuerySystemDescriptor.h
    Include/Atom/RPI.Reflect/Limits.h
    Include/Atom/RPI.Reflect/RPISystemDescriptor.h
    Include/Atom/RPI.Reflect/ResourcePoolAsset.h
    Include/Atom/RPI.Reflect/ResourcePoolAssetCreator.h
    Include/Atom/RPI.Reflect/Buffer/BufferAsset.h
    Include/Atom/RPI.Reflect/Buffer/BufferAssetCreator.h
    Include/Atom/RPI.Reflect/Buffer/BufferAssetView.h
    Include/Atom/RPI.Reflect/Model/ModelAsset.h
    Include/Atom/RPI.Reflect/Model/ModelKdTree.h
    Include/Atom/RPI.Reflect/Model/ModelLodAsset.h
    Include/Atom/RPI.Reflect/Model/ModelLodIndex.h
    Include/Atom/RPI.Reflect/Model/ModelMaterialSlot.h
    Include/Atom/RPI.Reflect/Model/ModelAssetCreator.h
    Include/Atom/RPI.Reflect/Model/ModelLodAssetCreator.h
    Include/Atom/RPI.Reflect/Model/MorphTargetDelta.h
    Include/Atom/RPI.Reflect/Model/MorphTargetMetaAsset.h
    Include/Atom/RPI.Reflect/Model/MorphTargetMetaAssetCreator.h
    Include/Atom/RPI.Reflect/Model/SkinJointIdPadding.h
    Include/Atom/RPI.Reflect/Model/SkinMetaAsset.h
    Include/Atom/RPI.Reflect/Model/SkinMetaAssetCreator.h
    Include/Atom/RPI.Reflect/Asset/AssetHandler.h
    Include/Atom/RPI.Reflect/Asset/AssetUtils.h
    Include/Atom/RPI.Reflect/Asset/AssetUtils.inl
    Include/Atom/RPI.Reflect/Asset/AssetReference.h
    Include/Atom/RPI.Reflect/Asset/BuiltInAssetHandler.h
    Include/Atom/RPI.Reflect/Image/AttachmentImageAsset.h
    Include/Atom/RPI.Reflect/Image/AttachmentImageAssetCreator.h
    Include/Atom/RPI.Reflect/Image/Image.h
    Include/Atom/RPI.Reflect/Image/ImageAsset.h
    Include/Atom/RPI.Reflect/Image/ImageMipChainAsset.h
    Include/Atom/RPI.Reflect/Image/ImageMipChainAssetCreator.h
    Include/Atom/RPI.Reflect/Image/ImageSystemDescriptor.h
    Include/Atom/RPI.Reflect/Image/StreamingImageAsset.h
    Include/Atom/RPI.Reflect/Image/StreamingImageAssetCreator.h
    Include/Atom/RPI.Reflect/Image/StreamingImageAssetHandler.h
    Include/Atom/RPI.Reflect/Image/StreamingImageControllerAsset.h
    Include/Atom/RPI.Reflect/Image/StreamingImagePoolAsset.h
    Include/Atom/RPI.Reflect/Image/StreamingImagePoolAssetCreator.h
    Include/Atom/RPI.Reflect/Material/LuaMaterialFunctor.h
    Include/Atom/RPI.Reflect/Material/LuaScriptUtilities.h
    Include/Atom/RPI.Reflect/Material/MaterialAsset.h
    Include/Atom/RPI.Reflect/Material/MaterialAssetCreator.h
    Include/Atom/RPI.Reflect/Material/MaterialDynamicMetadata.h
    Include/Atom/RPI.Reflect/Material/MaterialNameContext.h
    Include/Atom/RPI.Reflect/Material/MaterialPropertyDescriptor.h
    Include/Atom/RPI.Reflect/Material/MaterialPropertiesLayout.h
    Include/Atom/RPI.Reflect/Material/MaterialPropertyValue.h
    Include/Atom/RPI.Reflect/Material/MaterialTypeAsset.h
    Include/Atom/RPI.Reflect/Material/MaterialTypeAssetCreator.h
    Include/Atom/RPI.Reflect/Material/ShaderCollection.h
    Include/Atom/RPI.Reflect/Material/MaterialFunctor.h
    Include/Atom/RPI.Reflect/Material/MaterialVersionUpdate.h
    Include/Atom/RPI.Reflect/Pass/ComputePassData.h
    Include/Atom/RPI.Reflect/Pass/CopyPassData.h
    Include/Atom/RPI.Reflect/Pass/DownsampleMipChainPassData.h
    Include/Atom/RPI.Reflect/Pass/FullscreenTrianglePassData.h
    Include/Atom/RPI.Reflect/Pass/PassAsset.h
    Include/Atom/RPI.Reflect/Pass/PassAttachmentReflect.h
    Include/Atom/RPI.Reflect/Pass/PassData.h
    Include/Atom/RPI.Reflect/Pass/PassDescriptor.h
    Include/Atom/RPI.Reflect/Pass/PassName.h
    Include/Atom/RPI.Reflect/Pass/PassRequest.h
    Include/Atom/RPI.Reflect/Pass/PassTemplate.h
    Include/Atom/RPI.Reflect/Pass/RasterPassData.h
    Include/Atom/RPI.Reflect/Pass/RenderPassData.h
    Include/Atom/RPI.Reflect/Pass/SlowClearPassData.h
    Include/Atom/RPI.Reflect/Shader/ShaderCommonTypes.h
    Include/Atom/RPI.Reflect/Shader/ShaderAsset.h
    Include/Atom/RPI.Reflect/Shader/ShaderAssetCreator.h
    Include/Atom/RPI.Reflect/Shader/ShaderInputContract.h
    Include/Atom/RPI.Reflect/Shader/ShaderOptionGroup.h
    Include/Atom/RPI.Reflect/Shader/ShaderOptionGroupLayout.h
    Include/Atom/RPI.Reflect/Shader/ShaderOutputContract.h
    Include/Atom/RPI.Reflect/Shader/ShaderOptionTypes.h
    Include/Atom/RPI.Reflect/Shader/ShaderVariantKey.h
    Include/Atom/RPI.Reflect/Shader/ShaderVariantTreeAsset.h
    Include/Atom/RPI.Reflect/Shader/ShaderVariantAsset.h
    Include/Atom/RPI.Reflect/Shader/IShaderVariantFinder.h
    Include/Atom/RPI.Reflect/Shader/PrecompiledShaderAssetSourceData.h
    Include/Atom/RPI.Reflect/System/AnyAsset.h
    Include/Atom/RPI.Reflect/System/AssetAliases.h
    Include/Atom/RPI.Reflect/System/PipelineRenderSettings.h
    Include/Atom/RPI.Reflect/System/RenderPipelineDescriptor.h
    Include/Atom/RPI.Reflect/System/SceneDescriptor.h
    Source/RPI.Reflect/Base.cpp
    Source/RPI.Reflect/FeatureProcessorDescriptor.cpp
    Source/RPI.Reflect/GpuQuerySystemDescriptor.cpp
    Source/RPI.Reflect/RPISystemDescriptor.cpp
    Source/RPI.Reflect/Asset/AssetReference.cpp
    Source/RPI.Reflect/Asset/AssetUtils.cpp
    Source/RPI.Reflect/Asset/BuiltInAssetHandler.cpp
    Source/RPI.Reflect/Buffer/BufferAsset.cpp
    Source/RPI.Reflect/Buffer/BufferAssetCreator.cpp
    Source/RPI.Reflect/Buffer/BufferAssetView.cpp
    Source/RPI.Reflect/Model/ModelAsset.cpp
    Source/RPI.Reflect/Model/ModelKdTree.cpp
    Source/RPI.Reflect/Model/ModelLodAsset.cpp
    Source/RPI.Reflect/Model/ModelAssetCreator.cpp
    Source/RPI.Reflect/Model/ModelLodAssetCreator.cpp
    Source/RPI.Reflect/Model/ModelMaterialSlot.cpp
    Source/RPI.Reflect/Model/MorphTargetDelta.cpp
    Source/RPI.Reflect/Model/MorphTargetMetaAsset.cpp
    Source/RPI.Reflect/Model/MorphTargetMetaAssetCreator.cpp
    Source/RPI.Reflect/Model/SkinJointIdPadding.cpp
    Source/RPI.Reflect/Model/SkinMetaAsset.cpp
    Source/RPI.Reflect/Model/SkinMetaAssetCreator.cpp
    Source/RPI.Reflect/ResourcePoolAsset.cpp
    Source/RPI.Reflect/ResourcePoolAssetCreator.cpp
    Source/RPI.Reflect/Image/AttachmentImageAsset.cpp
    Source/RPI.Reflect/Image/AttachmentImageAssetCreator.cpp
    Source/RPI.Reflect/Image/Image.cpp
    Source/RPI.Reflect/Image/ImageAsset.cpp
    Source/RPI.Reflect/Image/ImageMipChainAsset.cpp
    Source/RPI.Reflect/Image/ImageMipChainAssetCreator.cpp
    Source/RPI.Reflect/Image/ImageSystemDescriptor.cpp
    Source/RPI.Reflect/Image/StreamingImageAsset.cpp
    Source/RPI.Reflect/Image/StreamingImageAssetCreator.cpp
    Source/RPI.Reflect/Image/StreamingImageAssetHandler.cpp
    Source/RPI.Reflect/Image/StreamingImageControllerAsset.cpp
    Source/RPI.Reflect/Image/StreamingImagePoolAsset.cpp
    Source/RPI.Reflect/Image/StreamingImagePoolAssetCreator.cpp
    Source/RPI.Reflect/Material/MaterialPropertyValue.cpp
    Source/RPI.Reflect/Material/MaterialAsset.cpp
    Source/RPI.Reflect/Material/MaterialAssetCreator.cpp
    Source/RPI.Reflect/Material/MaterialNameContext.cpp
    Source/RPI.Reflect/Material/LuaMaterialFunctor.cpp
    Source/RPI.Reflect/Material/LuaScriptUtilities.cpp
    Source/RPI.Reflect/Material/MaterialDynamicMetadata.cpp
    Source/RPI.Reflect/Material/MaterialPropertyDescriptor.cpp
    Source/RPI.Reflect/Material/MaterialPropertiesLayout.cpp
    Source/RPI.Reflect/Material/MaterialTypeAsset.cpp
    Source/RPI.Reflect/Material/MaterialTypeAssetCreator.cpp
    Source/RPI.Reflect/Material/ShaderCollection.cpp
    Source/RPI.Reflect/Material/MaterialFunctor.cpp
    Source/RPI.Reflect/Material/MaterialVersionUpdate.cpp
    Source/RPI.Reflect/Pass/PassAsset.cpp
    Source/RPI.Reflect/Pass/PassAttachmentReflect.cpp
    Source/RPI.Reflect/Pass/PassRequest.cpp
    Source/RPI.Reflect/Pass/PassTemplate.cpp
    Source/RPI.Reflect/Shader/ShaderStageType.cpp
    Source/RPI.Reflect/Shader/ShaderAsset.cpp
    Source/RPI.Reflect/Shader/ShaderAssetCreator.cpp
    Source/RPI.Reflect/Shader/ShaderInputContract.cpp
    Source/RPI.Reflect/Shader/ShaderOptionGroup.cpp
    Source/RPI.Reflect/Shader/ShaderOptionGroupLayout.cpp
    Source/RPI.Reflect/Shader/ShaderOutputContract.cpp
    Source/RPI.Reflect/Shader/ShaderVariantKey.cpp
    Source/RPI.Reflect/Shader/ShaderVariantTreeAsset.cpp
    Source/RPI.Reflect/Shader/ShaderVariantAsset.cpp
    Source/RPI.Reflect/Shader/PrecompiledShaderAssetSourceData.cpp
    Source/RPI.Reflect/System/AnyAsset.cpp
    Source/RPI.Reflect/System/AssetAliases.cpp
    Source/RPI.Reflect/System/RenderPipelineDescriptor.cpp
    Source/RPI.Reflect/System/SceneDescriptor.cpp
)
