/*
 * Copyright (c) Contributors to the Open 3D Engine Project.
 * For complete copyright and license terms please see the LICENSE at the root of this distribution.
 *
 * SPDX-License-Identifier: Apache-2.0 OR MIT
 *
 */

#include <AzCore/Utils/Utils.h>
#include <AzCore/IO/ByteContainerStream.h>
#include <AzCore/IO/FileIO.h>
#include <AzCore/IO/GenericStreams.h>
#include <AzCore/IO/SystemFile.h>
#include <AzCore/IO/Path/Path.h>
#include <AzCore/Settings/SettingsRegistry.h>
#include <AzCore/Settings/SettingsRegistryMergeUtils.h>
#include <AzCore/StringFunc/StringFunc.h>

namespace AZ::Utils
{
    ExecutablePathResult GetExecutableDirectory(char* exeStorageBuffer, size_t exeStorageSize)
    {
        AZ::Utils::GetExecutablePathReturnType result = GetExecutablePath(exeStorageBuffer, exeStorageSize);
        if (result.m_pathStored != AZ::Utils::ExecutablePathResult::Success)
        {
            *exeStorageBuffer = '\0';
            return result.m_pathStored;
        }

        // If it contains the filename, zero out the last path separator character...
        if (result.m_pathIncludesFilename)
        {
            AZ::IO::PathView exePathView(exeStorageBuffer);
            AZStd::string_view exeDirectory = exePathView.ParentPath().Native();
            exeStorageBuffer[exeDirectory.size()] = '\0';
        }

        return result.m_pathStored;
    }

    AZ::IO::FixedMaxPathString GetExecutableDirectory()
    {
        AZ::IO::FixedMaxPathString executableDirectory;
        if(GetExecutableDirectory(executableDirectory.data(), executableDirectory.capacity())
            == ExecutablePathResult::Success)
        {
            // Updated the size field within the fixed string by using char_traits to calculate the string length
            executableDirectory.resize_no_construct(AZStd::char_traits<char>::length(executableDirectory.data()));
        }

        return executableDirectory;
    }

    AZStd::optional<AZ::IO::FixedMaxPathString> ConvertToAbsolutePath(AZStd::string_view path)
    {
        AZ::IO::FixedMaxPathString absolutePath;
        AZ::IO::FixedMaxPathString srcPath{ path };
        if (ConvertToAbsolutePath(srcPath.c_str(), absolutePath.data(), absolutePath.capacity()))
        {
            // Fix the size value of the fixed string by calculating the c-string length using char traits
            absolutePath.resize_no_construct(AZStd::char_traits<char>::length(absolutePath.data()));
            return absolutePath;
        }

        return AZStd::nullopt;
    }

    bool ConvertToAbsolutePath(AZ::IO::FixedMaxPath& outputPath, AZStd::string_view path)
    {
        AZ::IO::FixedMaxPathString srcPath{ path };
        if (ConvertToAbsolutePath(srcPath.c_str(), outputPath.Native().data(), outputPath.Native().capacity()))
        {
            // Fix the size value of the fixed string by calculating the c-string length using char traits
            outputPath.Native().resize_no_construct(AZStd::char_traits<char>::length(outputPath.Native().data()));
            return true;
        }

        return false;
    }

    AZ::IO::FixedMaxPathString GetO3deManifestDirectory(AZ::SettingsRegistryInterface* settingsRegistry)
    {
        if (settingsRegistry == nullptr)
        {
            settingsRegistry = AZ::SettingsRegistry::Get();
        }

        if (settingsRegistry != nullptr)
        {
            AZ::SettingsRegistryInterface::FixedValueString settingsValue;
            if (settingsRegistry->Get(settingsValue, AZ::SettingsRegistryMergeUtils::FilePathKey_O3deManifestRootFolder))
            {
                return AZ::IO::FixedMaxPathString{ settingsValue };
            }
        }

        // If the O3DEManifest key isn't set in teh settings registry
        // fallback to use the user's home directory with the .o3de folder appended to it
        AZ::IO::FixedMaxPath path = GetHomeDirectory(settingsRegistry);
        path /= ".o3de";
        return path.Native();
    }

    AZ::IO::FixedMaxPathString GetO3deManifestPath(AZ::SettingsRegistryInterface* settingsRegistry)
    {
        AZ::IO::FixedMaxPath o3deManifestPath = GetO3deManifestDirectory(settingsRegistry);
        if (!o3deManifestPath.empty())
        {
            o3deManifestPath /= "o3de_manifest.json";
        }

        return o3deManifestPath.Native();
    }

    AZ::IO::FixedMaxPathString GetO3deLogsDirectory(AZ::SettingsRegistryInterface* settingsRegistry)
    {
        AZ::IO::FixedMaxPath path = GetO3deManifestDirectory(settingsRegistry);
        path /= "Logs";
        return path.Native();
    }

    AZ::IO::FixedMaxPathString GetEnginePath(AZ::SettingsRegistryInterface* settingsRegistry)
    {
        if (settingsRegistry == nullptr)
        {
            settingsRegistry = AZ::SettingsRegistry::Get();
        }

        if (settingsRegistry != nullptr)
        {
            if (AZ::IO::FixedMaxPathString settingsValue;
                settingsRegistry->Get(settingsValue, AZ::SettingsRegistryMergeUtils::FilePathKey_EngineRootFolder))
            {
                return settingsValue;
            }
        }
        return {};
    }

    AZ::IO::FixedMaxPathString GetProjectPath(AZ::SettingsRegistryInterface* settingsRegistry)
    {
        if (settingsRegistry == nullptr)
        {
            settingsRegistry = AZ::SettingsRegistry::Get();
        }

        if (settingsRegistry != nullptr)
        {
            if (AZ::IO::FixedMaxPathString settingsValue;
                settingsRegistry->Get(settingsValue, AZ::SettingsRegistryMergeUtils::FilePathKey_ProjectPath))
            {
                return settingsValue;
            }
        }
        return {};
    }

    AZ::SettingsRegistryInterface::FixedValueString GetProjectName(AZ::SettingsRegistryInterface* settingsRegistry)
    {
        if (settingsRegistry == nullptr)
        {
            settingsRegistry = AZ::SettingsRegistry::Get();
        }

        if (settingsRegistry != nullptr)
        {
            using FixedValueString = AZ::SettingsRegistryInterface::FixedValueString;
            FixedValueString projectNameKey{ AZ::SettingsRegistryMergeUtils::ProjectSettingsRootKey };
            projectNameKey += "/project_name";

            if (FixedValueString settingsValue;
                settingsRegistry->Get(settingsValue, projectNameKey))
            {
                return settingsValue;
            }
        }
        return {};
    }

    AZ::SettingsRegistryInterface::FixedValueString GetProjectDisplayName(AZ::SettingsRegistryInterface* settingsRegistry)
    {
        if (settingsRegistry == nullptr)
        {
            settingsRegistry = AZ::SettingsRegistry::Get();
        }

        if (settingsRegistry != nullptr)
        {
            using FixedValueString = AZ::SettingsRegistryInterface::FixedValueString;
            FixedValueString projectNameKey{ AZ::SettingsRegistryMergeUtils::ProjectSettingsRootKey };
            projectNameKey += "/display_name";

            if (FixedValueString settingsValue;
                settingsRegistry->Get(settingsValue, projectNameKey))
            {
                return settingsValue;
            }
        }
        // fallback to querying the "project_name", if the "display_name" could not be read
        return GetProjectName(settingsRegistry);
    }

    AZ::IO::FixedMaxPathString GetGemPath(AZStd::string_view gemName, AZ::SettingsRegistryInterface* settingsRegistry)
    {
        if (settingsRegistry == nullptr)
        {
            settingsRegistry = AZ::SettingsRegistry::Get();
        }

        if (settingsRegistry != nullptr)
        {
            using FixedValueString = AZ::SettingsRegistryInterface::FixedValueString;
            const auto manifestGemJsonPath = FixedValueString::format("%s/%.*s/Path",
                AZ::SettingsRegistryMergeUtils::ManifestGemsRootKey, AZ_STRING_ARG(gemName));

            if (AZ::IO::FixedMaxPathString settingsValue;
                settingsRegistry->Get(settingsValue, manifestGemJsonPath))
            {
                return settingsValue;
            }
        }
        return {};
    }

    AZ::IO::FixedMaxPathString GetProjectUserPath(AZ::SettingsRegistryInterface* settingsRegistry)
    {
        if (settingsRegistry == nullptr)
        {
            settingsRegistry = AZ::SettingsRegistry::Get();
        }


        if (settingsRegistry != nullptr)
        {
            if (AZ::IO::FixedMaxPathString settingsValue;
                settingsRegistry->Get(settingsValue, AZ::SettingsRegistryMergeUtils::FilePathKey_ProjectUserPath))
            {
                return settingsValue;
            }
        }
        return {};
    }

    AZ::Outcome<void, AZStd::string> WriteFile(AZStd::string_view content, AZStd::string_view filePath)
    {
        return WriteFile(AZStd::span(reinterpret_cast<const AZStd::byte*>(content.data()), content.size()), filePath);
    }

    AZ::Outcome<void, AZStd::string> WriteFile(AZStd::span<AZStd::byte const> content, AZStd::string_view filePath)
    {
        AZ::IO::FixedMaxPath filePathFixed = filePath; // Because FileIOStream requires a null-terminated string
        AZ::IO::FileIOStream stream(filePathFixed.c_str(), AZ::IO::OpenMode::ModeWrite | AZ::IO::OpenMode::ModeCreatePath);

        bool success = false;

        if (stream.IsOpen())
        {
            AZ::IO::SizeType bytesWritten = stream.Write(content.size(), content.data());

            if (bytesWritten == content.size())
            {
                success = true;
            }
        }

        if (success)
        {
            return AZ::Success();
        }
        else
        {
            return AZ::Failure(AZStd::string::format("Could not write to file '%s'", filePathFixed.c_str()));
        }
    }

    template<typename Container>
    AZ::Outcome<Container, AZStd::string> ReadFile(AZStd::string_view filePath, size_t maxFileSize)
    {
        IO::FileIOStream file;
        if (!file.Open(filePath.data(), IO::OpenMode::ModeRead))
        {
            return AZ::Failure(AZStd::string::format("Failed to open '%.*s'.", AZ_STRING_ARG(filePath)));
        }

        AZ::IO::SizeType length = file.GetLength();

        if (length > maxFileSize)
        {
            return AZ::Failure(AZStd::string{ "Data is too large." });
        }
        else if (length == 0)
        {
            return AZ::Failure(AZStd::string::format("Failed to load '%.*s'. File is empty.", AZ_STRING_ARG(filePath)));
        }

        Container fileContent;
        fileContent.resize_no_construct(length);
        AZ::IO::SizeType bytesRead = file.Read(length, fileContent.data());
        file.Close();

        // Resize again just in case bytesRead is less than length for some reason
        fileContent.resize_no_construct(bytesRead);
        return AZ::Success(AZStd::move(fileContent));
    }

    template AZ::Outcome<AZStd::string, AZStd::string> ReadFile(AZStd::string_view filePath, size_t maxFileSize);
    template AZ::Outcome<AZStd::vector<int8_t>, AZStd::string> ReadFile(AZStd::string_view filePath, size_t maxFileSize);
    template AZ::Outcome<AZStd::vector<uint8_t>, AZStd::string> ReadFile(AZStd::string_view filePath, size_t maxFileSize);
    template AZ::Outcome<AZStd::vector<AZStd::byte>, AZStd::string> ReadFile(AZStd::string_view filePath, size_t maxFileSize);
}
