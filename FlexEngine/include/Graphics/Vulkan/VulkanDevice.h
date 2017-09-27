#pragma once

#include <vulkan/vulkan.h>

#include "VDeleter.h"

namespace flex
{
	namespace vk
	{
		struct VulkanDevice
		{
			VulkanDevice(VkPhysicalDevice physicalDevice);

			glm::uint GetMemoryType(glm::uint typeBits, VkMemoryPropertyFlags properties, VkBool32* memTypeFound = nullptr) const;

			operator VkDevice();

			VkPhysicalDevice m_PhysicalDevice = VK_NULL_HANDLE;
			VDeleter<VkDevice> m_LogicalDevice{ vkDestroyDevice };
			VDeleter<VkCommandPool> m_CommandPool;

			VkPhysicalDeviceProperties m_PhysicalDeviceProperties;
			VkPhysicalDeviceFeatures m_PhysicalDeviceFeatures;
			VkPhysicalDeviceMemoryProperties m_MemoryProperties;
			std::vector<VkQueueFamilyProperties> m_QueueFamilyProperties;
			std::vector<std::string> m_SupportedExtensions;
			bool m_EnableDebugMarkers = false;
		};
	} // namespace vk
} // namespace flex
