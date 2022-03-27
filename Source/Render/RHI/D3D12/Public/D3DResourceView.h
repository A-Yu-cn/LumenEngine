#pragma once

#include "D3DDescriptorHeap.h"
#include "D3DResource.h"
#include "Render/RHI/Common/Public/RHIResourceView.h"

namespace Lumen::Render
{
    class D3DRenderTargetView : public RHIRenderTargetView
    {
    public:
        D3DRenderTargetView(RHIDevice* rhiDevice, D3DDescriptorHeap* descriptorHeap, D3DTexture* texture);

    public:
        D3D12_CPU_DESCRIPTOR_HANDLE                         descriptorHandle;
        D3DDescriptorHeap*                                  ownedDescriptorHeap;
    };

    class D3DDepthStencilView : public RHIDepthStencilView
    {
    public:
        D3DDepthStencilView(RHIDevice* rhiDevice, D3DDescriptorHeap* descriptorHeap, D3DTexture* texture);

    public:
        D3D12_CPU_DESCRIPTOR_HANDLE                         descriptorHandle;
        D3DDescriptorHeap*                                  ownedDescriptorHeap;
    };

    class D3DShaderResourceView : public RHIShaderResourceView
    {
    public:
        D3DShaderResourceView(RHIDevice* rhiDevice, D3DDescriptorHeap* descriptorHeap, D3DTexture* texture);

    public:
        D3D12_CPU_DESCRIPTOR_HANDLE                         cpuDescriptorHandle;
        D3DDescriptorHeap*                                  ownedDescriptorHeap;
    };
}