Cyclable = {
  __Cursor = 0,
  Items = {}
}

function Cyclable:new(o)
  local o = o or {}

  setmetatable(o, {__index = self})
  self.__index = self

  o.__Cursor = 0
  o.Items = { }

  return o
end

function Cyclable:destroy()
  self.Items = {}
  self.__Cursor = 0
  self = nil

  return nil
end

-- returns whether the cursor points at an object or not
function Cyclable:isValid()
  return self.__Cursor <= #self.Items and self.__Cursor > 0
end

-- convenience for checking whether this list has any items
function Cyclable:isEmpty()
  return self:count() == 0
end

function Cyclable:find(item)
  return find_by_value(self.Items, item)
end

-- this may return nil, watch out!
function Cyclable:get()
  --~ print("DEBUG: Cyclable cursor is now at: " .. self.__Cursor .. " out of " .. #self.Items)
  assert(self:isValid())
  return self.Items[self.__Cursor]
end

function Cyclable:isCurrent(item)
  return self.Items[self.__Cursor] == item
end

function Cyclable:add(item)
  table.insert(self.Items, item)
  return self
end

function Cyclable:remove(item)
  -- the cursor is invalidated, what do we do? get next or previous? reset?
  if self:isCurrent(item) then
    self:next()
  end

  remove_by_value(self.Items, item)
  return self
end

function Cyclable:remove_by_condition(cond)
  return remove_by_condition(self.Items, cond)
end

function Cyclable:next()
  -- if the cursor is at the end of the list, circle back to the first element
  if self.__Cursor == #self.Items then
    self.__Cursor = 0
  end

  self.__Cursor = self.__Cursor + 1

  return self:get()
end

function Cyclable:prev()
  -- if the cursor is at the beginning of the list, circle back to the last element
  if self.__Cursor <= 1 then
    self.__Cursor = #self.Items + 1
  end

  self.__Cursor = self.__Cursor - 1

  return self:get()
end

function Cyclable:reset(to_end)
  if to_end then
    self.__Cursor = #self.Items
  else
    self.__Cursor = 1
  end
  return self
end

function Cyclable:count()
  return #self.Items
end
