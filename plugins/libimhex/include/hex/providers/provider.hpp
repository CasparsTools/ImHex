#pragma once

#include <hex.hpp>

#include <map>
#include <optional>
#include <string>
#include <vector>

#include <hex/helpers/shared_data.hpp>
#include <hex/providers/overlay.hpp>

namespace hex::prv {

    class Provider {
    public:
        constexpr static size_t PageSize = 0x1000'0000;

        Provider();
        virtual ~Provider();

        virtual bool isAvailable() const = 0;
        virtual bool isReadable() const = 0;
        virtual bool isWritable() const = 0;
        virtual bool isResizable() const = 0;
        virtual bool isSavable() const = 0;

        virtual void read(u64 offset, void *buffer, size_t size, bool overlays = true);
        virtual void readRelative(u64 offset, void *buffer, size_t size, bool overlays = true);
        virtual void write(u64 offset, const void *buffer, size_t size);
        virtual void writeRelative(u64 offset, const void *buffer, size_t size);

        virtual void resize(ssize_t newSize);

        virtual void save();
        virtual void saveAs(const std::string &path);

        virtual void readRaw(u64 offset, void *buffer, size_t size) = 0;
        virtual void writeRaw(u64 offset, const void *buffer, size_t size) = 0;
        virtual size_t getActualSize() const  = 0;

        void applyOverlays(u64 offset, void *buffer, size_t size);

        std::map<u64, u8>& getPatches();
        const std::map<u64, u8>& getPatches() const;
        void applyPatches();

        [[nodiscard]] Overlay* newOverlay();
        void deleteOverlay(Overlay *overlay);
        [[nodiscard]] const std::list<Overlay*>& getOverlays();

        u32 getPageCount() const;
        u32 getCurrentPage() const;
        void setCurrentPage(u32 page);

        virtual void setBaseAddress(u64 address);
        virtual u64 getBaseAddress() const;
        virtual size_t getSize() const;
        virtual std::optional<u32> getPageOfAddress(u64 address) const;

        [[nodiscard]] virtual std::string getName() const = 0;
        [[nodiscard]] virtual std::vector<std::pair<std::string, std::string>> getDataInformation() const = 0;

        void addPatch(u64 offset, const void *buffer, size_t size);

        void undo();
        void redo();

        bool canUndo() const;
        bool canRedo() const;

    protected:
        u32 m_currPage = 0;
        u64 m_baseAddress = 0;

        u32 m_patchTreeOffset = 0;
        std::vector<std::map<u64, u8>> m_patches;
        std::list<Overlay*> m_overlays;
    };

}